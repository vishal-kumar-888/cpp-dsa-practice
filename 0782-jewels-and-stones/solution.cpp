class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        int hash[256] = {0};

        for (int i = 0; i < jewels.size(); i++) {
            hash[jewels[i]]++;
        }
        for (int i = 0; i < stones.size(); i++) {

            if(hash[stones[i]] > 0) count++;
        }
        return count;
    }
};
