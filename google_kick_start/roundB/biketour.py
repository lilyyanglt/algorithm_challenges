import sys


def getTotalCheckpoint(N, values):
    peakcount = 0
    index = 1
    while index < (N - 1):
        if int(values[index]) > int(values[index - 1]) and int(values[index]) > int(values[index + 1]):
            peakcount += 1
        index += 1

    return peakcount


if __name__ == "__main__":
    file = sys.stdin
    if len(sys.argv) >= 2:
        input_file = sys.argv[1]
        if input_file != '-':
            file = open(input_file)

    T = int(file.readline())
    for index in range(T):
        N = int(file.readline())
        values = file.readline().split()
        print("Case #%d: %d" % (index + 1, getTotalCheckpoint(N, values)))
