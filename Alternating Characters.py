def setTarget(value):
    '''setiing up the target'''
    if value=='A':
        return 'B'
    return 'A'

def alternatingCharacters(s):
    '''find minimum deletions'''
    point = s[0]
    target = setTarget(point)
    numDel = 0

    for i in range(1, len(s)):
        point = s[i]

        if point==target:
            point = target
            target = setTarget(point)
        else:
            numDel += 1

    return numDel