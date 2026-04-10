class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        // Interleave the first n elements with the remaining n elements
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[i]);     // Add xi
            ans.push_back(nums[i + n]); // Add yi
        }
        return ans;
    }
};
