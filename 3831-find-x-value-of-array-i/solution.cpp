#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // ans[x] stores the total number of subarrays whose product % k == x
        vector<long long> ans(k, 0);
        // dp[r] tracks the number of subarrays ending at the current position with product % k == r
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> new_dp(k, 0);
            long long num_mod = num % k;
            
            // 1. Start a new subarray containing only the current element
            new_dp[num_mod]++;
            
            // 2. Extend all valid subarrays that ended at the previous position
            for (int i = 0; i < k; ++i) {
                if (dp[i] > 0) {
                    long long new_mod = (i * num_mod) % k;
                    new_dp[new_mod] += dp[i];
                }
            }
            
            // 3. Accumulate the new subarray counts into our global answer
            for (int i = 0; i < k; ++i) {
                ans[i] += new_dp[i];
            }
            
            // Move to the next element
            dp = move(new_dp);
        }
        
        return ans;
    }
};

