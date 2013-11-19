#!/usr/bin/python2
"""Project Euler problem 59."""


with open('p59.txt', 'r') as f:
    line = list(map(int, f.readline().strip().split(',')))
    #print(list(map(lambda c: chr(c ^ 32), line)))
    a0 = line[0::3]
    a1 = line[1::3]
    a2 = line[2::3]
    print("#a0#")
    for alpha in range(ord('a'), ord('z')):

        def isnt_alpha(c):
            char = c ^ alpha
            if char < 127 and char > 31:
                return False
            else:
                return True

        if list(filter(isnt_alpha, a0)) == []:
            print(chr(alpha))

    print("#a1")
    for alpha in range(ord('a'), ord('z')):

        if list(filter(isnt_alpha, a1)) == []:
            print(chr(alpha))

    print("#a2")
    for alpha in range(ord('a'), ord('z')):

        if list(filter(isnt_alpha, a2)) == []:
            print(chr(alpha))

    _a0 = list(map(lambda c: chr(c ^ ord('g')), a0))
    _a1 = list(map(lambda c: chr(c ^ ord('o')), a1))
    _a2 = list(map(lambda c: chr(c ^ ord('d')), a2))
    for i in range(min(map(len, [_a0, _a1, _a2]))):
        print _a0[i],
        print _a1[i],
        print _a2[i],
