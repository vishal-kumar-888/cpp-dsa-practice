class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int left = 0, right = 0;
        int maxfreq = 0;
        while (right < n) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k) {
                freq[nums[left]]--; 
                left++;
            }
            maxfreq = max(right - left + 1, maxfreq);
            right++;
        }
        return maxfreq;
    }
};
