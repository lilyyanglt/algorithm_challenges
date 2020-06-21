// source: learned from mycodingschool but added additional 
// author: Lily Yang
// ***** THIS IS NOT THE OPTIMIZED VERSION DUE TO NOT USING RANDOMIZATION FOR PIVOT INDEX ***

#include <iostream>
#include <vector>
#include <utility> // for swap

// compare function to customize quicksort - asc or desc
bool ascending(int a, int b) {
  return (a <= b);
}

bool descending(int a, int b) {
  return (a >= b);
}

int partition(std::vector<int>& nums, int start, int end, bool(*compare)(int, int)) {
    int pivot = nums[end];
    int temp = 0, pIndex = start;
    
    for (int i = start; i < end; i++) {
        if(compare(nums[i], pivot)) {
            // can use swap(nums[i], nums[pIndex]) or 
            // swap(nums[pIndex], nums[i])
            temp = nums[i];
            nums[i] = nums[pIndex];
            nums[pIndex] = temp;
            pIndex++;
        } 
    }

    std::swap(nums[end], nums[pIndex]);
    
    return pIndex;
}

void quickSort(std::vector<int>& nums, int start, int end, bool(*compare)(int, int)) {
  if (start < end) {
      int pIndex = partition(nums, start, end, compare);

      quickSort(nums, start, pIndex - 1, compare);
      quickSort(nums, pIndex + 1, end, compare);
  }
}

int main(void) {
  std::vector<int> nums{1, 15, 8, 2, 6, 5};
  int n = nums.size();

  std::cout << "before sorting:\n";
  
  for (int n : nums) {
    std::cout << n << " ";
  }

  // passing ascending function to quickSort Algo
  std::cout << "\nafter sorting, ascending:\n";
  quickSort(nums, 0, n-1, &ascending);
  for (int n : nums) {
    std::cout << n << " ";
  }

  // passing descending function to quickSort Algo
  std::cout << "\nafter sorting, descending:\n";
  quickSort(nums, 0, n-1, &descending);
  for (int n : nums) {
    std::cout << n << " ";
  }

  std::cout << '\n';

  return 0;
}