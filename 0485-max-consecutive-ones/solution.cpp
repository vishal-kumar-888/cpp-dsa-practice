class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen =0, one =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){ maxlen = max(maxlen,one); 
            one=0;}
            else one++;
        }
        return maxlen<one?one:maxlen;
    }
};
