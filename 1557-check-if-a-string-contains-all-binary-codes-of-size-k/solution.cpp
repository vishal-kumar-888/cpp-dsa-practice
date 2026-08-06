class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> codes;
    int mask = (1 << k) - 1;
    int curr = 0;
    
    for (int i = 0; i < s.length(); i++) {
        curr = ((curr << 1) & mask) | (s[i] - '0');
        
        if (i >= k - 1) {
            codes.insert(curr);
            if (codes.size() == (1 << k)) return true;
        }
    }
    return false;
    }
};
