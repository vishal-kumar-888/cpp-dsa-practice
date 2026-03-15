class Solution {
public:
    void reverseString(vector<char>& s) {
       if( s.size() == 1) return;
        int left =0;
        int right = s.size()-1;
        while(left <= right){
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
    }
};
