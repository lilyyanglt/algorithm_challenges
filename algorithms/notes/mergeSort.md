# Merge Sort

## What is it?
- It's an algorithm that sorts elements in a linear data structure based on certain properties by using the divide and conquer approach. 

## Properties
- Uses divide and conquer paradigm
- It's not in place sorting
- Uses auxillary memory by creating new subarrays during each divide and conquer step so memory complexity is O(n)
- Time complexity is reduced from sorting algorithms such as selection, bubble, or insertion sort from O(n^2) to O(n log n)
- stable sorting algorithm (ie: that items sorted will retain its relative position and won't be disrupted because of sorting)

## Algorithm Description

1. divide original arrays into 2 equal subarrays recursively until length of each array is = 1 (base case)
1. merge subroutine takes place for each subarray and eventually merge it in the order

## I NEED GIFS TO DEMONSTRATE MY LEARNING!

## Complexity Analysis

## Implementation

- please see [here](https://github.com/lilyyanglt/algorithm_challenges/blob/master/algorithms/implementation/python/mergeSort.py)