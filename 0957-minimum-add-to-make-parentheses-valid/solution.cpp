class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;  // Tracks unmatched '('
        int close = 0; // Tracks unmatched ')'

        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    close++;
                }
            }
        }

        return open + close;
    }
};
