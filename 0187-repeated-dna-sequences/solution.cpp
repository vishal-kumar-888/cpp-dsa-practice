#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> ans;
        unordered_map<string, int> mp;

        int k = 10;

        for (int i = 0; i <= s.length() ; i++) {

            string window = s.substr(i, k);

            if (mp[window] == 1) {
                ans.push_back(window);
            }

            mp[window]++;
        }

        return ans;
    }
};
