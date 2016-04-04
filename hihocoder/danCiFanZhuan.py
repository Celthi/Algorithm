__author__ = 'celhipc'
## The code is wrong, I update it inoder to test some function and corret it in the future
def reverseStr(string):
    string = '[::-1]'
    return string


def reWords(s):
    i = 0
    j = 0
    state = False
    while i < len(s):
        j = i
        while i < (len(s) - 1) and s[i].isspace():
            i += 1
            j = i
        while j < (len(s) - 1) and s[j] != ' ':
            j += 1
            state = True
        if state:
            i = j
            state = False

    reverseStr(s)

if __name__ == '__main__':
    s = input()
    reverseStr(s)

    print(s)

