# Round B Summary

- I was able to complete the first problem which I think is a good milestone!
- The following summary includes different language used to solve the problems and notes to help anyone that is as confused as I was in how to handle the input.

## Bike Tour
* Python3 Attempt 1 - My submission

```python

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

```

* Python3 Attempt 2 - Inspired by contestant "huikang"

```python
# this takes in the first line of input which is the total test case
T = int(input())

for case in range(T):
    # take in the second line of input which is the integer N
    N = int(input())
    # take the third line of input which is the string of the values
    value_str = input()
    # turn each of items in the string input into a list of integers
    values = [int(x) for x in value_str.split()]

    peak_count = 0
    index = 1

    while index < N - 1:
        if values[index] > values[index - 1] and values[index] > values[index + 1]:
            peak_count += 1
        index += 1

    print("Case #{}: {}".format(case + 1, peak_count))
```

* C++

## Bus Routes
- TBD


## Robot Path Decoding
- TBD


## Wandering Robot