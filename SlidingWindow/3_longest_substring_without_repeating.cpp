// Problem: Longest Substring Without Repeating Characters
// LeetCode: 3
// Topic: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include<iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256, -1);

        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            if (lastSeen[s[right]] != -1) {
                cout<<"-> "<<s[right]<<endl;
                left = max(left, lastSeen[s[right]] + 1);
            }

            lastSeen[s[right]] = right;

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main(){

    Solution s1;
    cout<< "length of longest substring without repeating characters: "<< s1.lengthOfLongestSubstring("abcabcbb")<<endl;
}