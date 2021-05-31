import pickle

def input_seq (instruction, matches):
    print(matches)
    print(instruction)
    if len(matches) == 0:
        print('\n')
        addition = input(" > ")
        print('\n')
        return addition


def build_map_section (comments, m):
    for line in comments['section']:
        if line.lstrip().startswith(b'/*'):
            pass
        elif line.lstrip().startswith(b'*/'):
            pass
        else:
            try:
                instruction = list(filter(lambda a: a != b'', line.lstrip().split(b' ')))[2:]
            except:
                instruction = False

            if instruction:
                print(instruction)
                if instruction[0] not in m:
                    m[instruction[0]] = []
                matches = m[instruction[0]]
                print(matches)
                addition = input_seq(instruction, matches)
                if addition:
                    m[instructions[0]].append(addition)

    return m

def build_map (sections, m):
    print(m)
    try: 
        for section in sections:
            if section['type']:
                comments = section
                # out = build_map_section(section, out)
                for line in comments['section']:
                    if line.lstrip().startswith(b'/*'):
                        pass
                    elif line.lstrip().startswith(b'*/'):
                        pass
                    else:
                        try:
                            instruction = list(filter(lambda a: a != b'', line.lstrip().split(b' ')))[2:]
                        except IndexError:
                            instruction = False

                        if instruction:
                            if instruction[0] not in m:
                                m[instruction[0]] = []
                            matches = m[instruction[0]]
                            addition = input_seq(instruction, matches)
                            if addition:
                                m[instruction[0]].append(addition)
    except KeyboardInterrupt:
        pass

    return m

def preprocess_file(f):
    sections = []

    comment_switch = False

    section = []
    for line in f:
        stripped = line.lstrip()
        if stripped.startswith(b'/*'):
            sections.append({'type' : comment_switch, 'section': section})
            section = []
            section.append(line)
            comment_switch = True
        elif stripped.startswith(b'*/'):
            section.append(line)
            sections.append({'type' : comment_switch, 'section': section})
            section = []
            comment_switch = False
        else:
            section.append(line)

    return sections

if __name__ == "__main__":
    f = open('14d14.c', 'rb')
   
    sections = preprocess_file(f)
    try:
        g = open('test.map', 'rb')
        m = pickle.load(g)
    except:
        m = {}

    m = build_map(sections, m)
    g = open('test.map', 'wb')
    g.write(pickle.dumps(m))
    g.close()

