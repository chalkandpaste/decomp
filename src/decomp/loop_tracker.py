class LoopTracker:

    def __init__(self, block_index):
        self.block_index = block_index
        self.loc_to_loop_end = {}
        self.loc_to_loop_start = {}
        self.loc_to_loop_locs = {}
        self.not_loop_loc = {} # locs which are not in a loop

    def is_loop_start(self, loc):
        # print('is_loop_start', hex(loc))
        if loc in self.loc_to_loop_start:
            return loc == self.loc_to_loop_start[loc]
        elif loc in self.not_loop_loc:
            return False
        else:
            self.detect_loop(loc)
            if loc in self.loc_to_loop_start:
                return loc == self.loc_to_loop_start[loc]
    
    def get_loop_start(self, loc):
        if loc in self.loc_to_loop_start:
            return self.loc_to_loop_start[loc]
        elif loc not in self.not_loop_loc:
            return None
        else:
            return self.detect_loop(loc)
            if loc in self.loc_to_loop_end:
                return self.loc_to_loop_end[loc]
            else:
                return None
    
    def is_loop_end(self, loc):
        # print('is_loop_end', hex(loc))
        if loc in self.loc_to_loop_end:
            return loc == self.loc_to_loop_end[loc]
        elif loc in self.not_loop_loc:
            return False
        else:
            self.detect_loop(loc)
            if loc in self.loc_to_loop_end:
                return loc == self.loc_to_loop_end[loc]
    
    def get_loop_end(self, loc):
        if loc in self.loc_to_loop_end:
            return self.loc_to_loop_end[loc]
        elif loc not in self.not_loop_loc:
            return None
        else:
            return self.detect_loop(loc)
            if loc in self.loc_to_loop_end:
                return self.loc_to_loop_end[loc]
            else:
                return None

    def can_loop(self, loc):
        # print('can_loop', hex(loc))
        if loc in self.loc_to_loop_start:
            # print('in start')
            return True
        elif loc in self.not_loop_loc:
            # print('in not')
            return False
        else:
            return self.detect_loop(loc)

    def branch_intersects(self, reachable, loc):
        # print('branch_intersects', [hex(r) for r in reachable], hex(loc))

        search_locs = [loc]

        branch_locs = []

        seen = {}

        while len(search_locs) > 0:
            loc = search_locs.pop(0)
            block = self.block_index[loc]

            seen[loc] = True

            if loc in reachable:
                return True

            c_locs = block['children']

            for c in c_locs:
                if c not in seen and c not in search_locs:
                    search_locs.append(c)
                    branch_locs.append(c)

        # print('branch_locs', [hex(b) for b in branch_locs])

        for b in branch_locs:
            search_locs = [b]

            while len(search_locs) > 0:
                loc = search_locs.pop(0)
                seen[loc] = True

                if loc in reachable:
                    return True

                p_locs = self.block_index[loc]['parents']
                for p in p_locs:
                    if p not in seen and p not in search_locs:
                        search_locs.append(p)

        return False
    
    def detect_loop(self, start_loc):
        # print('detect_loop', hex(start_loc))
        # we want to first detect all the points in the loop, do this by making a loop path
        # asserting if it is maximal and then expanding if not maximal.
        # maximality of a loop is defined by having the set of points in the loop containing 
        # each points' parent and child nodes as well.
        # for each point, if the parent is loopable (can reach itself) add it to the set
        # for each point, if the child is loopable, at it to the set

        if start_loc in self.loc_to_loop_start:
            return True
        elif start_loc in self.not_loop_loc:
            return False
        
        search_locs = []
        if self._check_loop(start_loc):
            search_locs.append(start_loc)
        else: # if len(loop_locs) == 0:
            self.not_loop_loc[start_loc] = True
            return False
       
        loop_locs, entrance_loc, exit_loc = self._detect_loop_inner(search_locs)
        if entrance_loc is not None and exit_loc is not None:
            dont_follow = [entrance_loc, exit_loc]
            while len(loop_locs) > 0:
                loop_locs, entrance_loc, exit_loc = self._detect_loop_inner(loop_locs, dont_follow)
                dont_follow += [entrance_loc, exit_loc]

        return True
    
    def _check_loop(self, start_loc, dont_follow = []):
        print('_check_loop', hex(start_loc), [hex(df) for df in dont_follow])
        seen = {}
        search_locs = [start_loc]

        while len(search_locs) > 0:
            loc = search_locs.pop(-1)
            seen[loc] = True

            c_locs = [c for c in self.block_index[loc]['children']]

            for c in c_locs:
                # only need one counter-example
                if c == start_loc:
                    return True
                elif c not in seen and c not in search_locs and c not in dont_follow:
                    search_locs.append(c)
                else:
                    pass

        return False

    def _detect_loop_inner(self, search_locs, dont_follow = []):
        print('_detect_loop_inner', [hex(l) for l in search_locs], [hex(df) for df in dont_follow])
        seen = {}
        loop_locs = []

        while len(search_locs) > 0:
            loc = search_locs.pop(0)
            seen[loc] = True

            if loc not in self.not_loop_loc:
                if self._check_loop(loc, dont_follow):
                    if loc not in dont_follow:
                        loop_locs.append(loc)
                    for c in self.block_index[loc]['children']:
                        if c not in seen and c not in dont_follow and c not in search_locs:
                            search_locs.append(c)
                else:
                    self.not_loop_loc[loc] = True

            children_locs = [c for c in self.block_index[loc]['children']]
            # print('children_locs', [hex(c) for c in children_locs])


        # expand    
        # dangling arms
        # additional_locs = []

        # for loc in loop_locs:
            # c_locs = self.block_index[loc]['children']
            # for c in c_locs:
                # if c not in loop_locs:
                    # c_children = self.block_index[c]['children']
                    # if len(c_children) == 0:
                        # additional_locs.append(c)

        # loop_locs += additional_locs

        entrance_loc = None
        exit_loc = None

        for loc in loop_locs:
            p_locs = self.block_index[loc]['parents']
            for p in p_locs:
                if p not in loop_locs:
                    entrance_loc = loc

           
            c_locs = self.block_index[loc]['children']
            for c in c_locs:
                if c not in loop_locs:
                    exit_loc = loc
        
        # odd case of being a function end (i.e., loop with no return)
        # if exit_loc is None:
            # for loc in loop_locs:
                # c_locs = self.block_index[loc]['children']
                # if len(c_locs) == 1 and (c_locs[0] == entrance_loc): # or entrance_loc is None): 
                    # exit_loc = loc


        # odd case of being a function start
        if entrance_loc is None:
            for loc in loop_locs:
                p_locs = self.block_index[loc]['parents']
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

        for loc in loop_locs:
            self.loc_to_loop_start[loc] = entrance_loc
            self.loc_to_loop_end[loc] = exit_loc
            self.loc_to_loop_locs[loc] = loop_locs

        return loop_locs, entrance_loc, exit_loc
