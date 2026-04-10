#include <vector>
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        /* vector<int> ans;
        ans.reserve(nums.size() * 2);  */// Optional: Optimization for performance

        // Method 1: Using push_back
       /*  for (int i = 0; i < 2; i++) {
            for (int x : nums) {
                ans.push_back(x);
            }
        }
 */
        // Method 2: Direct initialization if you know the size
        vector<int> ans(nums.size() * 2);
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }
        return ans;
    }
    };
