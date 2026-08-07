class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;

        // Total sum - sum of n-k elements = max k cards
        for (int x : cardPoints)
            totalSum += x;
         if (k == n) return totalSum;

        int windowSize = n - k;
        int windowSum = 0;
        int minWindow = INT_MAX;

        // Find minimum sum of subarray of size (n-k)
        int left = 0, right = 0;
        while (right < n) {
            windowSum += cardPoints[right];

            if (right - left + 1 == windowSize) {
                minWindow = min(minWindow, windowSum);
                windowSum -= cardPoints[left];
                left++;
            }
            right++;
        }

        return totalSum - minWindow;
    }
};
