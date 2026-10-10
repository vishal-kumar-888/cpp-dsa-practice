class Solution {
public:
    int minimumRecolors(string nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int left =0,right =0;
        int white =0;
        while(right<n){

            if(nums[right]=='W'){
                white++;
            }
            if(right-left+1==k){
                ans = min(ans,white);
                if(nums[left]=='W') white--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
