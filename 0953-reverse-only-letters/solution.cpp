class Solution {
public:
    string reverseOnlyLetters(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        // Skip non-letters from left
        while (left < right && !isalpha(s[left])) left++;
        // Skip non-letters from right
        while (left < right && !isalpha(s[right])) right--;
        
        // Swap the letters
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}
};
