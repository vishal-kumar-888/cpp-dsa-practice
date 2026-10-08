class Solution {
public:

    int solve(string s, int k, char target) {

        int left = 0;
        int count = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            if (s[right] == target)
                count++;

            while (count > k) {

                if (s[left] == target)
                    count--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        int changeF = solve(answerKey, k, 'F');
        int changeT = solve(answerKey, k, 'T');

        return max(changeF, changeT);
    }
};
