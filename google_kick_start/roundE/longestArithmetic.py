"""
Aug 23, 2020
Google Kickstart Round E: Longest Arithmetic

Approach:
My approach is go through the elements in the array and make sure that
Ai+1 - Ai = Ai+2 - Ai+1, if they are not equal, then I will change the
current_longest subarray to be 2 since that's the smallest possible
subarray length and compare whether current_longest is bigger than longest,
if so, then longest become the current_longest value

In the end return whichever one is bigger: longest or current_longest

Time Complexity: O(n) - n is the total number of element in the array
Space Complexity: O(1)

"""

import unittest
import io
from unittest.mock import patch


def solve(N, arr):

    pd = arr[1] - arr[0]
    longest = 2
    current_longest = 2

    for i in range(1, N-1):
        cd = arr[i+1] - arr[i]
        if cd == pd:
            current_longest += 1
        else:
            if longest < current_longest:
                longest = current_longest
            current_longest = 2
        pd = cd

    return longest if longest > current_longest else current_longest


def main():
    T = int(input())
    for case in range(T):
        N = int(input())
        arr = [int(x) for x in input().split(" ")]
        result = solve(N, arr)
        print(f"Case #{case+1}: {result}")


class TestLongestArithmetic(unittest.TestCase):

    @patch('sys.stdout', new_callable=io.StringIO)
    @patch('builtins.input', side_effect=[4, 10, "5 4 3 2 1 2 3 4 5 6",
                                          4, "9 7 5 3",
                                          7, "10 7 4 6 8 10 11",
                                          9, "5 5 4 5 5 5 4 5 6"])
    def test_main(self, mock_input, mock_output):
        main()
        actual = (
            "Case #1: 6\n"
            "Case #2: 4\n"
            "Case #3: 4\n"
            "Case #4: 3\n"
        )
        self.assertEqual(mock_output.getvalue(), actual)

    def test_solve_a(self):
        result = solve(10, [5, 4, 3, 2, 1, 2, 3, 4, 5, 6])
        expected = 6
        self.assertEqual(result, expected)

    def test_solve_b(self):
        result = solve(4, [9, 7, 5, 3])
        expected = 4
        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()