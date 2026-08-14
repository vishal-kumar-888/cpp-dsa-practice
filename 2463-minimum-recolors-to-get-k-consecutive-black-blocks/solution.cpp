class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                white++;
            }
        }

        int ans = white;

        // Slide the window
        for (int right = k; right < blocks.size(); right++) {
            int left = right - k;

            // Remove the character leaving the window
            if (blocks[left] == 'W') {
                white--;
            }

            // Add the character entering the window
            if (blocks[right] == 'W') {
                white++;
            }

            ans = min(ans, white);
        }

        return ans;
    }
};
