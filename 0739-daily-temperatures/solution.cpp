class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int oldIndex = st.top();
                st.pop();

                ans[oldIndex] = i - oldIndex;
            }

            st.push(i);
        }

        return ans;
    }
};
