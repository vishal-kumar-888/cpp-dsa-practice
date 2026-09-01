class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        int freq[101] = {0};

        // Step 1: Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Prefix sum
        for (int i = 1; i <= 100; i++) {
            freq[i] += freq[i - 1];
        }

        // Step 3: Find answer
        vector<int> ans;

        for (int x : nums) {
            if (x == 0)
                ans.push_back(0);
            else
                ans.push_back(freq[x - 1]);
        }

        return ans;
    }
};
