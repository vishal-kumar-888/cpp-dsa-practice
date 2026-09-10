class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            // Number
            if (token != "+" && token != "-" &&
                token != "*" && token != "/") {

                st.push(stoi(token));
            }

            // Operator
            else {
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                int result;

                if (token == "+")
                    result = left + right;
                else if (token == "-")
                    result = left - right;
                else if (token == "*")
                    result = left * right;
                else
                    result = left / right;

                st.push(result);
            }
        }

        return st.top();
    }
};
