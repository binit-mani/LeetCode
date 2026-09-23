class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // longest subarray with (sum = total-x)
        map<int,int> mpp;
        mpp[0] = -1;
        int sum = 0;
        for(int it:nums) sum += it;
        if(sum == x)return nums.size();
        int val = sum-x;
        int ans = -1;
        sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mpp.find(sum-val) != mpp.end()){
                ans = max(ans,i-mpp[sum-val]);
            }
            mpp[sum] = i;
        }
        if(ans == -1)return -1;
        return nums.size()-ans;
    }
};