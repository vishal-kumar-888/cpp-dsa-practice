class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());


        int ans = nums[0] + nums[1] + nums[2];
        int minDiff = INT_MAX;
        for(int i = 0; i < nums.size()-2; i++) {
            int left = i+1;
            int right = nums.size()-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;
                else if(sum > target) {
                    right--;
                }
                else {
                    left++;
                } 

                int currDiff = abs(sum - target);
                if(currDiff < minDiff) {
                    ans = sum;
                    minDiff = currDiff;
                }
            }
            
        }
        return ans;
    }
};
