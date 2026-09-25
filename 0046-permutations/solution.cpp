class Solution {
public:

    void solve(vector<int>& nums,
               vector<int>& current,
               vector<bool>& used,
               vector<vector<int>>& ans)
    {
        // Base case
        if (current.size() == nums.size())
        {
            ans.push_back(current);
            return;
        }

        // Try every element
        for (int j = 0; j < nums.size(); j++)
        {
            // Already used
            if (used[j])
                continue;

            // TAKE
            used[j] = true;
            current.push_back(nums[j]);

            // RECURSE
            solve(nums, current, used, ans);

            // UNDO
            current.pop_back();
            used[j] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        solve(nums, current, used, ans);

        return ans;
    }
};
