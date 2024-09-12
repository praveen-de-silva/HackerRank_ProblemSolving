def setTarget(value):
    if value=='A':
        return 'B'
    return 'A'

def alternatingCharacters(s):
    point = s[0]
    target = setTarget(point)
    