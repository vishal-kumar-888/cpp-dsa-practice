// Problem: Nth Root of M
// Platform: GeeksforGeeks
// Topic: Binary Search
// Time Complexity: O(log m * n)

class Solution {
public:

    long long power(int mid, int n) {
        long long ans = 1;

        for (int i = 0; i < n; i++) {
            ans *= mid;
        }

        return ans;
    }

    int nthRoot(int n, int m) {

        int low = 1;
        int high = m;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long val = power(mid, n);

            if (val == m)
                return mid;

            else if (val < m)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};