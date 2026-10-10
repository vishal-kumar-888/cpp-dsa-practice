class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> ans(n, -1);

        if (n < windowSize) {
            return ans;
        }
        int right = 0;
        int left = 0;
        long long sum = 0;
        while (right < n) {
            sum += nums[right];
            if (right - left + 1 == windowSize) {
                
                ans[left + k] = sum/windowSize;
                sum -= nums[left++];
            }
            right++;
        }
    
        return ans;
    }
};
