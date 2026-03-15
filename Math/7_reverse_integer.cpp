// Problem: Reverse Integer
// LeetCode: 7
// Topic: Math
// Time Complexity: O(log10(n))
// Space Complexity: O(1)
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        long long reversed = 0;

        while (x != 0) {

            int digit = x % 10;

            reversed = reversed * 10 + digit;

            x /= 10;
        }

        if (reversed > INT_MAX || reversed < INT_MIN)
            return 0;

        return (int)reversed;
    }
};

int main(){

    Solution s1;
    cout<< "reversed: "<< s1.reverse(123)<<endl;
}