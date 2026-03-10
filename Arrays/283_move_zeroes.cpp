

// Problem: Move Zeroes
// LeetCode: 283
// Topic: Arrays / Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {

    int j = -1;

    // Find first zero
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) return;

    for (int i = j + 1; i < nums.size(); i++) {

        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}