class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /* int indexsum = 0;
        int arrsum = 0;
        for(int i=0;i<nums.size();i++){
            arrsum += nums[i];
            indexsum++;
        }
        int indexsum1 =0;
        for(int i=1;i<=indexsum;i++){

            indexsum1 +=i;
        }

        return (indexsum1 - arrsum); */
        int res = nums.size(); // Start with n (the last index)
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;       // XOR the index (0, 1, 2... n-1)
            res ^= nums[i]; // XOR the array element
        }
        return res;
    }
};
