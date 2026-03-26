class Solution {
public:
    string reverseWords(string s) {
    int n = s.size();
    int left = 0, right = 0;

    // Step 1: Clean spaces (Two-pointer technique)
    while (right < n) {
        while (right < n && s[right] == ' ') right++; // Skip leading/extra spaces
        if (right < n) {
            if (left != 0) s[left++] = ' '; // Add a single space between words
            int start = left;
            while (right < n && s[right] != ' ') {
                s[left++] = s[right++]; // Shift word to the left
            }
            // Step 2: Reverse the current word
            reverse(s.begin() + start, s.begin() + left);
        }
    }
    
    // Step 3: Trim the garbage at the end and reverse the entire string
    s.erase(s.begin() + left, s.end());
    reverse(s.begin(), s.end());

    return s;
}

    
};
