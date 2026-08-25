class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int small = k;
        for(int i = k;;i+=k){
            int ind = lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(ind>=nums.size() || nums[ind]!=i)return i;
            small += k;
        }
        return small;
    }
};