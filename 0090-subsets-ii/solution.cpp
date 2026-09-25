class Solution {
public:

    void solve(vector<int>& nums, int i,
               vector<int>& current,
               vector<vector<int>>& ans)
    {
        ans.push_back(current);

        for (int j = i; j < nums.size(); j++)
        {
            // Skip duplicate choices at the same level
            if (j > i && nums[j] == nums[j - 1])
                continue;

            // TAKE
            current.push_back(nums[j]);

            solve(nums, j + 1, current, ans);

            // UNDO
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(nums, 0, current, ans);

        return ans;
    }
};
