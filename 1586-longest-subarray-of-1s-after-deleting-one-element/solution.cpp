class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left =0, right =0, ziro=0;
        int maxlen = INT_MIN;

        for(right =0;right<nums.size();right++){
            if(nums[right]==0) ziro++;
            while(ziro>1){
                if(nums[left]==0) ziro--;

                left++;
            }
            maxlen = max(maxlen, right-left+1);
            
        }
        return maxlen== INT_MIN ? 0 : maxlen-1;
    }
};
