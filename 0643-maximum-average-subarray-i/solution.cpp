class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum =0;
        double max_avg=0;
        double avg =0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        max_avg = sum/k;
        for(int i=k;i<nums.size();i++){
            sum = (sum - nums[i-k]) + nums[i];
            avg = sum/k;
            max_avg = max(max_avg,avg);
        }
        return max_avg;
    }
};
