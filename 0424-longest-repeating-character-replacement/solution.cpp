class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans =0, l=0,r=0,mf =0;
        int hashmap[256]={0};
        for(int r=0;r<s.size();r++){
            hashmap[s[r]]++;
            mf = max(mf,hashmap[s[r]]);
            while((r-l+1)-mf>k){
                hashmap[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
            
        return ans;
    }
};
