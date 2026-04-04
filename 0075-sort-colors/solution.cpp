class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ziros =0,ones =0,twos =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0) ziros++;
            else if(nums[i]==1) ones++;
            else twos++;
        }
        for(int i =0;i<nums.size();i++){
            if(ziros!=0){
                nums[i]=0;
                ziros--;
            }
            else if(ones!=0){
                nums[i]=1;
                ones--;
            }
            else {
                nums[i]=2;
                twos--;
            }
        }
    }
};
