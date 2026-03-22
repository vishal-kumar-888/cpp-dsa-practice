// Problem: Maximum Product of Two Elements in an Array
// LeetCode: 1464
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {

        int maxi = INT_MIN;
        int second = INT_MIN;

        for (int num : arr) {

            if (num > maxi) {
                second = maxi;
                maxi = num;
            }
            else if (num > second) {
                second = num;
            }
        }

        return (maxi - 1) * (second - 1);
    }
};