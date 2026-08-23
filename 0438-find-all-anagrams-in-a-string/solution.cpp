class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        
        
        vector<int> ans;
        int need[256] = {0};
        int window[256] = {0};
        
        // Count characters in pattern t
        for (char c : t) {
            need[c]++;
        }
        
        int have = 0;
        int req = 0; // Number of distinct characters needed
        
        // Count distinct characters in t
        for (int i = 0; i < 256; i++) {
            if (need[i] > 0) req++;
        }
        
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // Add character at right pointer
            char rightChar = s[right];
            window[rightChar]++;
            
            // If this character's count matches the requirement
            if (need[rightChar] > 0 && window[rightChar] == need[rightChar]) {
                have++;
            }
            
            // Shrink window if it's larger than t
            while (right - left + 1 > t.size()) {
                char leftChar = s[left];
                
                // If removing this character breaks a match
                if (need[leftChar] > 0 && window[leftChar] == need[leftChar]) {
                    have--;
                }
                
                window[leftChar]--;
                left++;
            }
            
            // Check if we have a valid permutation
            if (have == req) {
                ans.push_back(left);
            }
        }
        
        return ans;
    }
};

