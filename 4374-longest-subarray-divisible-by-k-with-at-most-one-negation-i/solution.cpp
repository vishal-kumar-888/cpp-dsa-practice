#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    inline int getMod(long long val, int k) {
        int rem = val % k;
        if (rem < 0) rem += k;
        return rem;
    }

public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        // Maps a prefix remainder to its earliest index
        unordered_map<int, int> earliest_idx;
        earliest_idx[0] = -1; // Base case: prefix sum of 0 at index -1

        // 1. First pass: Find longest subarrays with ZERO negations
        // and populate the earliest occurrence map.
        long long pref = 0;
        vector<int> pref_rem(n); // Store remainders for second pass lookups
        
        for (int j = 0; j < n; j++) {
            pref += nums[j];
            int rem = getMod(pref, k);
            pref_rem[j] = rem;

            if (earliest_idx.find(rem) != earliest_idx.end()) {
                maxLen = max(maxLen, j - earliest_idx[rem]);
            } else {
                earliest_idx[rem] = j;
            }
        }

        // 2. Second pass: Treat each index 'm' as the ONLY negated element.
        // We look for any valid 'j' >= 'm' that can use this negation.
        // To do this optimally without O(N^2), we can flip the perspective:
        // For every ending index 'j', look back at elements 'm' we could negate.
        
        // Let's use an array tracking the absolute minimum starting index 
        // that matches our target remainder requirement.
        for (int j = 0; j < n; j++) {
            for (int m = 0; m <= j; m++) {
                // Target starting remainder we need to find in earliest_idx
                long long target = (long long)pref_rem[j] - getMod(2LL * nums[m], k);
                int target_rem = getMod(target, k);

                if (earliest_idx.find(target_rem) != earliest_idx.end()) {
                    int start_idx = earliest_idx[target_rem];
                    // The negated element 'm' MUST be inside the subarray, meaning start_idx < m
                    if (start_idx < m) {
                        maxLen = max(maxLen, j - start_idx);
                    }
                }
            }
        }

        return maxLen;
    }
};

