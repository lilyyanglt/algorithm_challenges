// source: learned from mycodingschool
// author: Lily Yang
// ***** THIS IS NOT THE OPTIMIZED VERSION DUE TO NOT USING RANDOMIZATION FOR PIVOT INDEX ***

#include <iostream>
#include <vector>

int partition(std::vector<int>& nums, int start, int end) {
    int pivot = nums[end];
    int temp, pIndex = start;
    
    for (int i = start; i < end; i++) {
        if(nums[i] <= pivot) {
            temp = nums[i];
            nums[i] = nums[pIndex];
            nums[pIndex] = temp;
            pIndex++;
        }
    }
    
    return pIndex;
}

void quickSort(std::vector<int>& nums, int start, int end) {
  int pIndex;
  if (start < end) {
      pIndex = partition(nums, start, end);

      quickSort(nums, start, pIndex - 1);
      quickSort(nums, pIndex + 1, end);
  }
}

int main(void) {
  std::vector<int> nums{1, 15, 8, 2, 6, 5};

  std::cout << "before sorting:\n";
  
  for (int n : nums) {
    std::cout << n << " ";
  }

  quickSort(nums, 0, nums.size()-1);

  std::cout << "\nafter sorting:\n";

  for (int n : nums) {
    std::cout << n << " ";
  }

  std::cout << '\n';

  return 0;
}