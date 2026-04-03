class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    long long sum = 0, max_sum = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        // Add current element
        freq[nums[right]]++;
        sum += nums[right];
        
        // If duplicate appears, shrink from left until unique
        while (freq[nums[right]] > 1) {
            freq[nums[left]]--;
            sum -= nums[left];
            left++;
        }
        
        // If window size == k, record answer and slide left
        if (right - left + 1 == k) {
            max_sum = max(max_sum, sum);
            // Remove leftmost element to continue sliding
            freq[nums[left]]--;
            sum -= nums[left];
            left++;
        }
    }
    return max_sum;
    }
};
