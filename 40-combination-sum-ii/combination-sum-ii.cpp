class Solution {
public:
    void f(vector<int> &candidates,int target,int pos,vector<vector<int>>& ans,vector<int> &t){
        if(target == 0){
            ans.push_back(t);return;
        }
        for(int i = pos;i<candidates.size();i++){
            if(i>pos && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target)break;
            t.push_back(candidates[i]);
            f(candidates,target - candidates[i],i+1,ans,t);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> t;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        f(candidates,target,0,ans,t);
        return ans;
    }
};