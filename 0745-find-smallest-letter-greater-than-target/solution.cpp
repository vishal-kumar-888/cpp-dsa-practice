class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // char ans = letters[0];
        // int cnt=0;
        // for(int i =0;i<letters.size();i++){
        //     if(cnt==1) return ans;
        //     if(letters[i] > target){
        //         ans = letters[i];
        //         cnt++;
        //     }
        // }
        // return ans;
         auto it = std::upper_bound(letters.begin(), letters.end(), target);
    
    // If upper_bound returns end, wrap around to first element
    if (it == letters.end()) {
        return letters[0];
    }
    return *it;
        
    }
};
