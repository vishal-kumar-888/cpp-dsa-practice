// Problem: Single Number
// LeetCode: 136
// Topic: Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};