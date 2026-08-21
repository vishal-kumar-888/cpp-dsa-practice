class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0, right =0, sum =0;
        int minimal_len = INT_MAX;
        for(right =0;right<nums.size();right++){
            sum += nums[right];

            while(sum >= target){
                minimal_len = min(minimal_len, right-left+1);  
                sum -= nums[left];
                left++;
            }  
        }

       return minimal_len == INT_MAX ? 0 : minimal_len;
        
    }
};
