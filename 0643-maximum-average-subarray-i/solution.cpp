class Solution {
public:
double findMaxAverage(vector<int>& nums, int k) {
    int left = 0, sum = 0, maxSum = INT_MIN;
    
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        
        if (right - left + 1 == k) {
            maxSum = max(maxSum, sum);
            sum -= nums[left];
            left++;
        }
    }
    return (double)maxSum / k;
}
    
};
