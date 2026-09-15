class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        for(int i=0;i<(1<<nums.size());i++){
            vector<int> t;
            for(int j=1;j<(1<<nums.size());j*=2){
                if((i&j) != 0){
                    t.push_back(nums[log2(j)]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};