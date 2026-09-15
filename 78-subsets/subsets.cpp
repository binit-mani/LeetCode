class Solution {
public:
    void f(vector<vector<int>> &ans,vector<int> &nums,vector<int> t,int index){
        if(index == nums.size()){
            ans.push_back(t);
            return;    
        }
        t.push_back(nums[index]);
        f(ans,nums,t,index+1);
        t.pop_back();
        f(ans,nums,t,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        f(ans,nums,{},0);
        return ans;
    }
};