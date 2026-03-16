// Problem: Rotate Array
// LeetCode: 189
// Topic: Arrays
// Technique: Reverse Array
// Time Complexity: O(n)
// Space Complexity: O(1)
#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};

int main(){
    Solution s1;
    vector<int> arr ={ 1,2,3,4,5,6,7};
    for(auto it: arr){
        cout<<" "<<it;
    }
    cout<<endl;
    int k = 3;
    s1.rotate(arr, k);
     
    for(auto it: arr){
        cout<<" "<<it;
    }

    return 0;
}