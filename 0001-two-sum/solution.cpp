class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*  for(int i=0;i<nums.size();i++){
             for(int j=i+1; j<nums.size();j++){
                 if(nums[i]+nums[j]==target){
                     return {i,j};
                 }
             }
         }
         return {-1,-1}; */
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            // Check if the complement exists in the map
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            // Store current value and its index
            seen[nums[i]] = i;
        }
        return {}; // No solution found
    }
};
