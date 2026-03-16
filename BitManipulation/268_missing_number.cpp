// Problem: Missing Number
// LeetCode: 268
// Topic: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }

        return res;
    }
};