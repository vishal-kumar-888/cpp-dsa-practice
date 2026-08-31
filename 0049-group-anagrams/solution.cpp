class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string word : strs) {

            // 1. Count frequency of each character
            int freq[26] = {0};

            for (char c : word) {
                freq[c - 'a']++;
            }

            // 2. Build a unique key from frequencies
            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]);
                key += "#";
            }

            // 3. Same frequency → same hashmap key
            mp[key].push_back(word);
        }

        // 4. Convert hashmap values into answer
        vector<vector<string>> ans;

        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
