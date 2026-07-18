from __future__ import annotations

from collections import deque
from collections.abc import Iterable
from dataclasses import dataclass
from typing import Protocol


class LoopGraph(Protocol):
    def successors(self, address: int) -> tuple[int, ...]:
        pass

    def predecessors(self, address: int) -> tuple[int, ...]:
        pass


@dataclass(frozen=True)
class LoopInfo:
    start: int | None
    end: int | None
    locations: tuple[int, ...]


@dataclass(frozen=True)
class LoopDetection:
    locations: tuple[int, ...]
    entrance: int | None
    exit: int | None

    def to_loop_info(self) -> LoopInfo:
        return LoopInfo(
            start=self.entrance,
            end=self.exit,
            locations=self.locations,
        )


class LoopTracker:

    def __init__(self, graph: LoopGraph) -> None:
        self.graph = graph
        self._loc_to_loop: dict[int, LoopInfo] = {}
        self.not_loop_loc: set[int] = set() # locs which are not in a loop

    def is_loop_start(self, loc: int) -> bool:
        # print('is_loop_start', hex(loc))
        loop = self.loop_info(loc)
        if loop is not None:
            return loc == loop.start
        elif loc in self.not_loop_loc:
            return False
        else:
            self.detect_loop(loc)
            loop = self.loop_info(loc)
            if loop is not None:
                return loc == loop.start
            return False
    
    def get_loop_start(self, loc: int) -> int | None:
        loop = self.loop_info(loc)
        return None if loop is None else loop.start
    
    def is_loop_end(self, loc: int) -> bool:
        # print('is_loop_end', hex(loc))
        loop = self.loop_info(loc)
        if loop is not None:
            return loc == loop.end
        elif loc in self.not_loop_loc:
            return False
        else:
            self.detect_loop(loc)
            loop = self.loop_info(loc)
            if loop is not None:
                return loc == loop.end
            return False
    
    def get_loop_end(self, loc: int) -> int | None:
        loop = self.loop_info(loc)
        return None if loop is None else loop.end

    def loop_info(self, loc: int) -> LoopInfo | None:
        return self._loc_to_loop.get(loc)

    def loop_locations(self, loc: int) -> tuple[int, ...]:
        loop = self.loop_info(loc)
        return () if loop is None else loop.locations

    def can_loop(self, loc: int) -> bool:
        # print('can_loop', hex(loc))
        if loc in self._loc_to_loop:
            # print('in start')
            return True
        elif loc in self.not_loop_loc:
            # print('in not')
            return False
        else:
            return self.detect_loop(loc)

    def branch_intersects(self, reachable: Iterable[int], loc: int) -> bool:
        # print('branch_intersects', [hex(r) for r in reachable], hex(loc))

        reachable_locs = set(reachable)
        search_locs: deque[int] = deque([loc])

        branch_locs: list[int] = []

        seen: set[int] = set()

        while search_locs:
            loc = search_locs.popleft()

            seen.add(loc)

            if loc in reachable_locs:
                return True

            for c in self.graph.successors(loc):
                if c not in seen and c not in search_locs:
                    search_locs.append(c)
                    branch_locs.append(c)

        # print('branch_locs', [hex(b) for b in branch_locs])

        for b in branch_locs:
            search_locs = deque([b])

            while search_locs:
                loc = search_locs.popleft()
                seen.add(loc)

                if loc in reachable_locs:
                    return True

                p_locs = self.graph.predecessors(loc)
                for p in p_locs:
                    if p not in seen and p not in search_locs:
                        search_locs.append(p)

        return False
    
    def detect_loop(self, start_loc: int) -> bool:
        # print('detect_loop', hex(start_loc))
        # we want to first detect all the points in the loop, do this by making a loop path
        # asserting if it is maximal and then expanding if not maximal.
        # maximality of a loop is defined by having the set of points in the loop containing 
        # each points' parent and child nodes as well.
        # for each point, if the parent is loopable (can reach itself) add it to the set
        # for each point, if the child is loopable, at it to the set

        if start_loc in self._loc_to_loop:
            return True
        elif start_loc in self.not_loop_loc:
            return False
        
        search_locs = []
        if self._check_loop(start_loc):
            search_locs.append(start_loc)
        else: # if len(loop_locs) == 0:
            self.not_loop_loc.add(start_loc)
            return False
       
        detection = self._detect_loop_inner(search_locs)
        if detection.entrance is not None and detection.exit is not None:
            dont_follow = (detection.entrance, detection.exit)
            while len(detection.locations) > 0:
                detection = self._detect_loop_inner(detection.locations, dont_follow)
                if detection.entrance is not None and detection.exit is not None:
                    dont_follow += (detection.entrance, detection.exit)

        return True
    
    def _check_loop(self, start_loc: int, dont_follow: Iterable[int] | None = None) -> bool:
        if dont_follow is None:
            dont_follow = ()
        dont_follow = tuple(dont_follow)
        dont_follow_locs = set(dont_follow)
        print('_check_loop', hex(start_loc), [hex(df) for df in dont_follow])
        seen: set[int] = set()
        search_locs = [start_loc]

        while search_locs:
            loc = search_locs.pop(-1)
            seen.add(loc)

            c_locs = [c for c in self.graph.successors(loc)]

            for c in c_locs:
                # only need one counter-example
                if c == start_loc:
                    return True
                elif c not in seen and c not in search_locs and c not in dont_follow_locs:
                    search_locs.append(c)
                else:
                    pass

        return False

    def _detect_loop_inner(
        self,
        search_locs: Iterable[int],
        dont_follow: Iterable[int] | None = None,
    ) -> LoopDetection:
        if dont_follow is None:
            dont_follow = ()
        search_locs = tuple(search_locs)
        dont_follow = tuple(dont_follow)
        dont_follow_locs = set(dont_follow)
        print('_detect_loop_inner', [hex(l) for l in search_locs], [hex(df) for df in dont_follow])
        seen: set[int] = set()
        loop_locs: list[int] = []
        pending_locs: deque[int] = deque(search_locs)

        while pending_locs:
            loc = pending_locs.popleft()
            seen.add(loc)

            if loc not in self.not_loop_loc:
                if self._check_loop(loc, dont_follow_locs):
                    if loc not in dont_follow_locs:
                        loop_locs.append(loc)
                    for c in self.graph.successors(loc):
                        if c not in seen and c not in dont_follow_locs and c not in pending_locs:
                            pending_locs.append(c)
                else:
                    self.not_loop_loc.add(loc)

            # print('children_locs', [hex(c) for c in self.graph.successors(loc)])


        # expand    
        # dangling arms
        # additional_locs = []

        # for loc in loop_locs:
            # for c in self.graph.successors(loc):
                # if c not in loop_locs and len(self.graph.successors(c)) == 0:
                    # additional_locs.append(c)

        # loop_locs += additional_locs

        entrance_loc = None
        exit_loc = None

        loop_loc_set = set(loop_locs)

        for loc in loop_locs:
            p_locs = self.graph.predecessors(loc)
            for p in p_locs:
                if p not in loop_loc_set:
                    entrance_loc = loc

           
            c_locs = self.graph.successors(loc)
            for c in c_locs:
                if c not in loop_loc_set:
                    exit_loc = loc
        
        # odd case of being a function end (i.e., loop with no return)
        # if exit_loc is None:
            # for loc in loop_locs:
                # c_locs = self.graph.successors(loc)
                # if len(c_locs) == 1 and (c_locs[0] == entrance_loc): # or entrance_loc is None): 
                    # exit_loc = loc


        # odd case of being a function start
        if entrance_loc is None:
            for loc in loop_locs:
                p_locs = self.graph.predecessors(loc)
                if len(p_locs) == 1 and p_locs[0] == exit_loc: 
                    entrance_loc = loc

        # print('detect_loop', hex(start_loc))
        # print("entrance_loc", hex(entrance_loc) if entrance_loc is not None else None)
        # print("exit_loc", hex(exit_loc) if exit_loc is not None else None)
        # print("loop_locs", [hex(l) for l in loop_locs])

        if (entrance_loc is not None and exit_loc is None) or (entrance_loc is None and exit_loc is not None):
            print("entrance_loc", hex(entrance_loc) if entrance_loc is not None else None)
            print("exit_loc", hex(exit_loc) if exit_loc is not None else None)
            print("loop_locs", [hex(l) for l in loop_locs])
            raise Exception

        detection = LoopDetection(
            locations=tuple(loop_locs),
            entrance=entrance_loc,
            exit=exit_loc,
        )
        loop = detection.to_loop_info()
        for loc in loop_locs:
            self._loc_to_loop[loc] = loop

        return detection
