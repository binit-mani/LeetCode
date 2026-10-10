class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int,int>> dq;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front().first <= i-k)dq.pop_front();
            while(!dq.empty() && dq.back().second < nums[i]) dq.pop_back();
            dq.push_back({i,nums[i]});
            if(i>=k-1){
                ans.push_back(dq.front().second);
            }
        }
        return ans;
    }
};