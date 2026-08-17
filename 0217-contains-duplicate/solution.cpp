
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create a hash set to keep track of numbers we have seen
    //     unordered_set<int> seen;
        
    //     for (int i = 0; i < nums.size(); i++) {
    //         // If the number is already in the set, we found a duplicate
    //         if (seen.find(nums[i]) != seen.end()) {
    //             return true;
    //         }
    //         // Otherwise, insert the number into the set
    //         seen.insert(nums[i]);
    //     }
        
    //     // If the loop finishes, all numbers are unique
    //     return false;
    // }

    sort(nums.begin(),nums.end());

    for (int i = 1; i < nums.size(); i++) {
        if(nums[i-1]==nums[i]) return true;
    }
    return false;
    }
};

    
