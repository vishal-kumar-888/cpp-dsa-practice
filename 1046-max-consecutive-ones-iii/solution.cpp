class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0,r=0,ml=0,z=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]==0) z++;
            if(z>k){
                if(nums[l]==0){
                    z--;
                }
                l++;
            }
            ml = max(ml,r-l+1);
        }
        return ml;
    }
};
