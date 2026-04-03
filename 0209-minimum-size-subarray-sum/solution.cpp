class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          int left = 0;
    int current_sum = 0;
    int min_len = INT_MAX; // Initialize with the Max Int we discussed!

    for (int right = 0; right < nums.size(); right++) {
        current_sum += nums[right]; // Expand the window

        // While the window meets the condition, try to shrink it
        while (current_sum >= target) {
            min_len = std::min(min_len, right - left + 1);
            current_sum -= nums[left];
            left++;
        }
    }

    // If min_len was never updated, return 0
    return (min_len == INT_MAX) ? 0 : min_len;

    }
};
