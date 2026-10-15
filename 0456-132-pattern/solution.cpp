#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        std::stack<int> stk;
        int nums_k = INT_MIN; // Represents the '2' in the 132 pattern

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If we find a number smaller than nums_k, we found our '1' (nums[i] < nums[k] < nums[j])
            if (nums[i] < nums_k) {
                return true;
            }

            // Maintain a decreasing stack. 
            // If the current number is greater than the stack top, the stack top becomes a valid 'nums_k'
            while (!stk.empty() && nums[i] > stk.top()) {
                nums_k = stk.top();
                stk.pop();
            }

            // Push the current number as a candidate for 'nums_j' ('3')
            stk.push(nums[i]);
        }

        return false;
    }
};

