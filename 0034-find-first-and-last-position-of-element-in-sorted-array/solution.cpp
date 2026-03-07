class Solution {
public:

int solve1(int n, int key, vector<int>& v) {
  // initialize search bounds and result
  int start = 0;
  int end = n - 1;
  int res = -1;

  // binary search loop
  while (start <= end) {
    // compute mid safely
    int mid = start + (end - start) / 2;
    // when match found, store index and move right
    if (v[mid] == key) {
      res = mid;
      start = mid + 1;
    }
    // when key is smaller, move left
    else if (key < v[mid]) {
      end = mid - 1;
    }
    // otherwise move right
    else {
      start = mid + 1;
    }
  }
  // return last occurrence or -1
  return res;
}

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int second = solve1(n,target,nums);
        int first = firstOccurrence(nums,n,target);
        
        return {first,second};
    }
};
