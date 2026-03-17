class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long reverse =0;
        int n = x;
        while(n!=0){
        int last = n%10;
        reverse = reverse *10+last;
        n = n/10; 
        }
        if(reverse == x){
            return true;
        }
        return false;
    }
};
