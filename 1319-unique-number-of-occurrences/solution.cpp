class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int> seen;

        for (int x : arr) {
            freq[x]++;
        }

        for (auto it : freq) {
            if (seen.count(it.second))
                return false;

            seen.insert(it.second);
        }
        return true;
    }
};
