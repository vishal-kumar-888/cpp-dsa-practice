// Problem: Find the Peaks
// LeetCode: 2951
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {

        vector<int> peaks;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peaks.push_back(i);
            }
        }

        return peaks;
    }
};