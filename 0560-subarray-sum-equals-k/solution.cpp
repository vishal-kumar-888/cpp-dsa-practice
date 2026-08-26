class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int currentsum = 0;
        unordered_map<int, int> hashmap;
         hashmap[0] = 1;
        for (int start = 0; start < nums.size(); start++) {
            currentsum += nums[start];
           int needed = (currentsum - k);
            if( hashmap.find(needed) != hashmap.end())
              count += hashmap[needed];
            hashmap[currentsum]++;
        }
        return count;
    }
};
