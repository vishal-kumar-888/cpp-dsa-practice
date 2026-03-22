class Solution {
public:
    int maxProduct(vector<int>& arr) {
    int maxi = 0;
    int second = 0;

    for (int num : arr) {
        if (num > maxi) {
            
            second = maxi;
            maxi = num;
        } else if (num > second) {
            
            second = num;
        }
    }

    return (maxi - 1) * (second - 1);
}
};
