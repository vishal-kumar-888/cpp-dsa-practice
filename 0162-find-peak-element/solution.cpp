class Solution {
public:
    // int findPeakElement(vector<int>& nums) {
        //     int n = nums.size();
        //    for (int i = 0; i < n; i++) {
        //         // Check left neighbor if exists
        //         bool left = (i == 0) || (nums[i] >= nums[i - 1]);
        //         // Check right neighbor if exists
        //         bool right = (i == n - 1) || (nums[i] >= nums[i + 1]);

        //         // If both sides are valid, return index
        //         if (left && right) return i;
        //     }

        //     // In case no peak found (shouldn't happen)
        //     return -1;
        // }

         int findPeakElement(vector<int>& nums) {
        // Set left and right bounds
        int low = 0, high = nums.size() - 1;

        // Binary search loop
        while (low < high) {
            // Find mid point
            int mid = (low + high) / 2;

            // If mid element is greater than next
            if (nums[mid] > nums[mid + 1]) {
                // Move to left half
                high = mid;
            } else {
                // Move to right half
                low = mid + 1;
            }
        }

        // Return peak index
        return low;
    }
};
