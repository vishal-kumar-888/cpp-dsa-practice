class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    //     int n = nums.size(), ans = 0;

    //     for(int i = 0; i < n; i++) {
    //         int product = 1;

    //         for(int j = i; j < n; j++) {
    //             product *= nums[j];

    //             if(product < k)
    //                 ans++;
    //             else
    //                 break;
    //         }
    //     }

    //     return ans;
    // }

     if(k <= 1) return 0;

    int left =0, right =0,ans =0;
    double product =1;
    for(right =0;right<nums.size();right++){
        product*=nums[right];
        while(product>=k){
            product/=nums[left];
            left++;
        }
        ans += (right-left+1);
    }
    return ans;
    }
};
