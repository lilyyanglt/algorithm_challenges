# Quick Sort
> source: https://www.youtube.com/watch?v=COk73cpQbFQ

## What is it?
- It's an algorithm that sorts elements in a linear data structure based on certain properties by using the divide and conquer approach, similar to Merge Sort, but in terms of memory, this algorithm is not using additiional memory. 

## Properties
- Uses divide and conquer paradigm
- It's in-place sorting (so that's why it doesn't need extra memory)
- Time complexity is reduced from sorting algorithms such as selection, bubble, or insertion sort from O(n^2) to O(n log n)
- Not stable sorting algorithm (ie: that items sorted will retain its relative position and won't be disrupted because of sorting)

## Algorithm Description

1. requires the use of partitioning subrouting that will return a pivot Index and rearranges the original array so that all the elements to the left of the pIndex is less than the pIndex value and all the elements to the right of the pIndex will be greater than the pIndex value
1. recursively call 

## Partitioning subroutine

- The routine and algorithm used for getting the pivot Index is a determining factor to ensure we won't have O(n^2) worst case.

**Non randomized approach**
- If you are using this approach with an unbalanced array (the array is already sorted, and you pick the last element as the pivot)
* Runtime: O(n^2)
* Space: O(1)

**Randomized Approach**
- <span style="color:red">TO DO: NEED TO INCLUDE RANDOMIZATION PARTITIONING IMPLEMENTATION</span>
* Runtime: O(nlogn)
* Space: O(1)

## Complexity Analysis

## I NEED GIFS TO DEMONSTRATE MY LEARNING!

## Implementation

- please see [here](https://github.com/lilyyanglt/algorithm_challenges/blob/master/algorithms/implementation/cpp/quickSort.cpp)