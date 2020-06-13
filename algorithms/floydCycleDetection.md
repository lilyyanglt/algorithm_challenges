# Floyd Cycle Detection Algorithm
> source: https://dev.to/alisabaj/floyd-s-tortoise-and-hare-algorithm-finding-a-cycle-in-a-linked-list-39af
> source: https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare

Time Complexity: O(n)
Space Complexity: O(1)

- This algorithm is also known as tortoise and hare algorithm, it's used to detect if there's cycle in a sequence
- Usually it's used in a linked list, but it can also be used to apply to problems where you want to detect if there's a repeating pattern in a certain sequence (e.g. [problem 202 on leetcode](https://leetcode.com/problems/happy-number/))
- You basically use 2 pointers, one moves twice as slow as the other one, so slow pointer moves 1 step at a time, and faster pointer moves 2 steps at a time, and eventually, if there's a cycle, the slow one and the fast one will be equal to each other! That's the beauty of this algorithm because it will always be the case that the slow pointer equaling to the fast pointer.
- For additional code examples of using this algorith, see [202 notes]()