#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        // min_lens[i] stores the minimum length of a valid sub-array found in arr[0...i]
        // Using a large number (like n + 1) to represent infinity to prevent integer overflow
        const int INF = n + 1; 
        std::vector<int> min_lens(n, INF);
        
        int left = 0;
        int current_sum = 0;
        int min_total_len = INF;
        int best_single_len = INF;
        
        // Sliding window
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // Shrink window from the left if the sum exceeds the target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            
            // If we found a valid sub-array equal to the target
            if (current_sum == target) {
                int current_len = right - left + 1;
                
                // If a valid sub-array exists strictly BEFORE our left pointer,
                // we can safely pair them together because they do not overlap.
                if (left > 0 && min_lens[left - 1] != INF) {
                    min_total_len = std::min(min_total_len, current_len + min_lens[left - 1]);
                }
                
                // Update the best single sub-array length found up to the current right pointer
                best_single_len = std::min(best_single_len, current_len);
            }
            
            // Record the best length found up to index 'right'
            min_lens[right] = best_single_len;
        }
        
        return (min_total_len > n) ? -1 : min_total_len;
    }
};
