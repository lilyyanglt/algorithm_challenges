T = int(input())

for case in range(T):
    info = [int(x) for x in input().split()]
    array = [int(x) for x in input().split()]
    print(array.index(info[1]))