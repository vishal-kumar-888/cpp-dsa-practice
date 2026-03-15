// Problem: Reverse String
// LeetCode: 344
// Topic: Two Pointers / Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};

int main(){

    Solution s1;
    
}