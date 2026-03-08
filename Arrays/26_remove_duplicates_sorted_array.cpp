// Problem: Remove Duplicates from Sorted Array
// LeetCode: 26
// Topic: Arrays / Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    int i = 0;

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}