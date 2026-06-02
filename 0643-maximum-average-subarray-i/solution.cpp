class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       double sum = 0;
        double maxavg = 0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxavg = sum;
        for(int j=1;j<nums.size()-k+1;j++){
            sum = (sum-nums[j-1])+(nums[j+k-1]);
            maxavg = max(maxavg,sum);
        }
        return double(maxavg/k);
    }
};
