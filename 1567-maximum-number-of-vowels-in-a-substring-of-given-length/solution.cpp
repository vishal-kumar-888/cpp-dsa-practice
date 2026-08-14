class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = 0;

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        ans = count;

        // Slide the window
        for (int right = k; right < s.size(); right++) {

            // Remove the character leaving the window
            int left = right - k;

            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                s[left] == 'o' || s[left] == 'u') {
                count--;
            }

            // Add the new character entering the window
            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
                s[right] == 'o' || s[right] == 'u') {
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
