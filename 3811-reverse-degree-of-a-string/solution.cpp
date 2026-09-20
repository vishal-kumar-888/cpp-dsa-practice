class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        for(int i=1;i<=s.size();i++){
          int alph = i *(123 - s[i-1]);
          ans+=alph;
        }
        return ans;
    }
};
