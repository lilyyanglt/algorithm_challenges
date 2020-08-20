/**********************************************************************************
* implementation of merge sort algorithm
* Date: Aug 19, 2020
***********************************************************************************/

#include <iostream>
#include <vector>

typedef std::vector<int> v;

void mergeSort(v& arr) {
  int n = arr.size();
  if (n < 2) return;

  // create auxillary arrays to hold all the left values in l 
  // create auxillary arrays to hold all the right values in r

  int mid = n/2;
  v left, right;

  for (int i = 0; i < n; i++) {
    if (i < mid) {
      left.push_back(arr[i]);
    } else {
      right.push_back(arr[i]);
    }
  }

  mergeSort(left);
  mergeSort(right);

  int k = 0, i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
      // compare
      if (left[i] < right[j]) {
        arr[k++] = left[i++];
      } else {
        arr[k++] = right[j++];
      }
    }

    // check if there's left over l elements

    while (i < left.size()) {
      arr[k++] = left[i++];
    }

    // check if there's left over r elements
    while (j < right.size()) {
      arr[k++] = right[j++];
    }

}


int main() {
 
  v nums = {2,5,6,1,0,4,3};

  mergeSort(nums);

  for (int value : nums) {
    std::cout << " " << value << std::endl;
  }

  std::cout << std::endl;

  return 0;

}