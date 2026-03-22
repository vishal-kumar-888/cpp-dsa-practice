// Problem: Matrix Diagonal Sum
// LeetCode: 1572
// Topic: Matrix
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += mat[i][i]; // primary diagonal

            if (i != n - i - 1) {
                sum += mat[i][n - i - 1]; // secondary diagonal
            }
        }

        return sum;
    }
};