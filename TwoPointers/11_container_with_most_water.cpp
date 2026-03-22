// Problem: Container With Most Water
// LeetCode: 11
// Topic: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {

            int width = right - left;
            int h = min(height[left], height[right]);

            maxArea = max(maxArea, width * h);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};