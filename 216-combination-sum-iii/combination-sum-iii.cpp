class Solution {
public:
    void solve(int k,int n,int pos,int cnt,int sum,vector<vector<int>> &ans,vector<int> &t){
        if(sum == n && k == cnt){
            ans.push_back(t);return;
        }
        if(sum > n)return;
        if(cnt>k)return;
        if(pos>=10)return;
        sum += pos;
        t.push_back(pos);
        solve(k,n,pos+1,cnt+1,sum,ans,t);
        t.pop_back();
        sum -= pos;
        solve(k,n,pos+1,cnt,sum,ans,t);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        solve(k,n,1,0,0,ans,t);
        return ans;
    }
};