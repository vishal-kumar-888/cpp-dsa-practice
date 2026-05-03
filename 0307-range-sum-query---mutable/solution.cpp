class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        pre.resize(nums.size());
        pre[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i] = pre[i-1] + nums[i];
        }
    }
    
    void update(int index, int val) {
    // Calculate the difference between the new value and the original value
    int originalVal = (index == 0) ? pre[0] : pre[index] - pre[index - 1];
    int diff = val - originalVal;

    // Update all prefix sums from 'index' to the end
    for (int i = index; i < pre.size(); i++) {
        pre[i] += diff;
    }
}
    
    int sumRange(int left, int right) {
        if(left == 0 ) return pre[right];
        return pre[right] - pre[left-1];
    }
};


    
    

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
