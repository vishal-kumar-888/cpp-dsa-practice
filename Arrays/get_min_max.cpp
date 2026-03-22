// Problem: Find Minimum and Maximum in Array
// Topic: Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

vector<int> getMinMax(vector<int> &arr) {

    int mini = arr[0];
    int maxi = arr[0];

    for (int i = 1; i < arr.size(); i++) {

        if (arr[i] > maxi)
            maxi = arr[i];

        if (arr[i] < mini)
            mini = arr[i];
    }

    return {mini, maxi};
}