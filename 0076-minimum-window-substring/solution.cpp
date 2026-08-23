class Solution {
public:
    string minWindow(string s, string t) {

        int need[256] = {0};
        int window[256] = {0};

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int have = 0;
        int req = t.size();

        int min_len = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            window[s[right]]++;

            if (need[s[right]] > 0 &&
                window[s[right]] <= need[s[right]]) {
                have++;
            }

            while (have == req) {

                int len = right - left + 1;

                if (len < min_len) {
                    min_len = len;
                    start = left;
                }

                char leftChar = s[left];

                window[leftChar]--;

                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        if (min_len == INT_MAX)
            return "";

        return s.substr(start, min_len);
    }
};
