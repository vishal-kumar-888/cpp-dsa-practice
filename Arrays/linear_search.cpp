// Problem: Linear Search
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

int search(vector<int>& arr, int x) {

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x)
            return i;
    }

    return -1;
}