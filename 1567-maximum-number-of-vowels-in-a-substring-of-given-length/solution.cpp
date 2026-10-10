class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> vovels(128);
        vovels['a']++;
        vovels['e']++;
        vovels['i']++;
        vovels['o']++;
        vovels['u']++;
        int n = s.size();

        int right =0;
        int left =0;
        int ans = 0;
        int cnt =0;
        while(right<n){
            if(vovels[s[right]]==1) cnt++;
            if(right-left+1==k){
                ans = max(ans,cnt);
                if(vovels[s[left]]==1){
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};
