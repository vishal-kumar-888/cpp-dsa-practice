class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);

        int l = 0, r = 0, maxlen = 0;
        int n = s.size();

        while (r < n) {
            // If character was seen before, move left pointer
            // to the right of the previous occurrence
            if (hash[s[r]] != -1) {
                l = max(hash[s[r]] + 1, l);
            }

            // Update last seen index and calculate length
            hash[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
