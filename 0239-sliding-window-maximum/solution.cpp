class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;

        for (int right = 0; right < nums.size(); right++) {

            // Remove elements smaller than current
            while (!dq.empty() &&
                   nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            dq.push_back(right);

            // Remove elements outside the window
            int left = right - k + 1;

            if (dq.front() < left) {
                dq.pop_front();
            }

            // Window is ready
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
