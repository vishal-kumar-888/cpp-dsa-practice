class Solution {
public:
    void ab(vector<vector<int>>& ans, vector<int>& nums, vector<int>& cu,
            int i) {

        if (i == nums.size()) {
            ans.push_back(cu);
            return;
        }
       

        // TAKE
        cu.push_back(nums[i]);
        ab(ans, nums, cu, i + 1);

        // UNDO
        cu.pop_back();

        // SKIP
        ab(ans, nums, cu, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cu;

        ab(ans, nums, cu, 0);

        return ans;
    }
};
