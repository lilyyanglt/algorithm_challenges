import re


def isPalindrome(s: str) -> bool:
    ns = re.sub(r'(\s)|(\W)', '', s).lower()
    length = len(ns) // 2
    temp = len(ns) - 1

    for i in range(length):
        print(i)
        print(temp)
        print('The end character: ', ns[temp])
        print('The beginning character: ', ns[i])
        print("----------------------------------")
        if ns[i] != ns[temp]:
            return False
        temp = temp - 1

    return True

isPalindrome("rbebr")