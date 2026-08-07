class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int totalSatisfied = 0;

        // Calculate total satisfied without using technique
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                totalSatisfied += customers[i];
            }
        }

        // Find max extra satisfied using technique
        int extraSatisfied = 0;
        int maxExtra = 0;
        int left = 0, right = 0;

        while (right < n) {
            if (grumpy[right] == 1) {
                extraSatisfied += customers[right];
            }

            if (right - left + 1 == minutes) {
                maxExtra = max(maxExtra, extraSatisfied);
                if (grumpy[left] == 1) {
                    extraSatisfied -= customers[left];
                }
                left++;
            }
            right++;
        }

        return totalSatisfied + maxExtra;
    }
};
