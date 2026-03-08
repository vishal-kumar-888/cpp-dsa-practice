// Problem: Search Insert Position
// Platform: LeetCode
// Problem No: 35
// Concept: Binary Search (Lower Bound)
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}