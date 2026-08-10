class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> anss;
        int n = nums.size();
        
        // 1️⃣ Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the current smallest number is > 0, 
            // no three numbers can sum up to 0.
      
            
            // 2️⃣ Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 3️⃣ Initialize two pointers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    anss.push_back({nums[i], nums[left], nums[right]});
                    
                    // 4️⃣ Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move pointers inward after processing
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // Sum is too small, make it bigger by moving left pointer
                    left++;
                } 
                else {
                    // Sum is too big, make it smaller by moving right pointer
                    right--;
                }
            }
        }
        return anss;
    }
};
