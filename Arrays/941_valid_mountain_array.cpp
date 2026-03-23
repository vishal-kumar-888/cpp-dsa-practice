// Problem: Valid Mountain Array
// LeetCode: 941
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int n = arr.size();
        if (n < 3) return false;

        int i = 0;

        // climb up
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // peak must not be first or last
        if (i == 0 || i == n - 1) return false;

        // go down
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};