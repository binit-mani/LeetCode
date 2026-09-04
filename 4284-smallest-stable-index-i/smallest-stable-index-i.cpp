class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> suff(nums.size());
        int mini = INT_MAX;
        for(int i = nums.size()-1;i>=0;i--){
            suff[i] = min(mini,nums[i]);
            mini = min(mini,nums[i]);
        }
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            if((maxi-suff[i]) <= k)return i;
        }
        return -1;
    }
};