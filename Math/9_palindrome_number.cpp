// Problem: Palindrome Number
// LeetCode: 9
// Topic: Math
// Time Complexity: O(log n)
// Space Complexity: O(1)
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {

            reversedHalf = reversedHalf * 10 + x % 10;

            x /= 10;
        }

        return (x == reversedHalf || x == reversedHalf / 10);
    }
};