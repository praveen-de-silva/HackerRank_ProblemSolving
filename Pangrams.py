# ==================
# PROGRAM : Pangrams
# ==================

def pangrams(s):
    '''check 's' is pangram'''
    s_lowerCase = s.lower()

    for i in range(97, 123):
        if chr(i) not in s_lowerCase:
            return 'not pangram'
            break
    else:
        return 'pangram'