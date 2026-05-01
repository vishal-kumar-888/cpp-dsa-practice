//Topic: Prefix sum
// Time Complexity: O(n)
// Space Complexity: O(1)

#include<iostream>
#include<vector>
using namespace std;

vector<int> Build_prefix_sum_array(const vector<int> &arr){
    int n = arr.size();
    vector<int> prefix_sum(n);
    
    prefix_sum[0] = arr[0];

    for(size_t i=1;i<n;i++){
        prefix_sum[i]= prefix_sum[i-1] + arr[i];
    }

    return prefix_sum;
}

// in-place 
vector<int> Build_prefix_sum_array_in_place(vector<int> &arr){
    for(size_t i=1;i<arr.size();i++){
        arr[i]+= arr[i-1];
    }

    return arr;
}


int main(){
    vector<int> arr ={ 1,2,3,4,5,6};
    vector<int> prefix_sum = Build_prefix_sum_array(arr);

    for(size_t it: prefix_sum){
        cout<<it <<" ";
    }
    cout<<endl;

     vector<int> prefix_sum_in_place = Build_prefix_sum_array_in_place(arr);

    for(size_t it: prefix_sum_in_place){
        cout<<it <<" ";
    }
    cout<<endl;
}