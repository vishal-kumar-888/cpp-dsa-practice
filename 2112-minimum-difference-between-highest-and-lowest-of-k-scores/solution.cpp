class Solution {
public:
   int minimumDifference(vector<int>& nums, int k) {
    // SPECIAL STEP: Sort first (because we need smallest difference)
    sort(nums.begin(), nums.end());
    
    int left = 0, right = 0;
    int ans = INT_MAX;
    
    while (right < nums.size()) {
        // 1️⃣ EXPAND: Window naturally grows as right moves
        // No windowData to add here!
        
        // 2️⃣ CHECK: window size == k
        if (right - left + 1 == k) {
            // 3️⃣ UPDATE: Calculate difference of current window
            int diff = nums[right] - nums[left];  // ← DIFFERENT!
            ans = min(ans, diff);                 // ← DIFFERENT!
            
            // 4️⃣ SHRINK: Just move left
            left++;  // ← DIFFERENT! No subtraction needed
        }
        right++;
    }
    return ans;
}
};
