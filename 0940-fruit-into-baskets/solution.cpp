class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int distinct = 0;
        int maximumfruits =0;

        unordered_map<int, int> freq;
        for (right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;

            if (freq[fruits[right]] == 1)
                distinct++;
            while (distinct > 2) {
                freq[fruits[left]]--;

                if (freq[fruits[left]] == 0)
                    distinct--;

                left++;
            }
            maximumfruits = max(maximumfruits,right-left+1);

        }
        return maximumfruits;
    }
};
