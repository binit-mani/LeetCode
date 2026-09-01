class Solution {
public:
    void sol(vector<int> &candidates,int target,int sum,int pos,vector<vector<int>> &ans,vector<int> &t){
        if(sum == target){
            ans.push_back(t);return;
        }
        if(sum > target)return;
        if(pos >= candidates.size())return;
        sum += candidates[pos];
        t.push_back(candidates[pos]);
        sol(candidates,target,sum,pos,ans,t);
        sum -= candidates[pos];
        t.pop_back();
        sol(candidates,target,sum,pos+1,ans,t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        sol(candidates,target,0,0,ans,t);
        return ans;
    }
};