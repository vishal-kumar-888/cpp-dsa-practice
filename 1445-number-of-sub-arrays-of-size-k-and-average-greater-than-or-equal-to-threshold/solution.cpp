class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int left = 0, right = 0;
    int sum = 0, count = 0;
    int n = arr.size();
    
    while (right < n) {
        sum += arr[right];
        
        if (right - left + 1 == k) {
            if (sum / k >= threshold) count++;
            sum -= arr[left];
            left++;
        }
        right++;
    }
    return count;
    }
};
