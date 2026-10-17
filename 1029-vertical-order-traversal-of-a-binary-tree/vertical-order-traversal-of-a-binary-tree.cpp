/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mpp;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            mpp[x][y].insert(node->val);
            if(node->left)q.push({node->left,{x-1,y+1}});
            if(node->right)q.push({node->right,{x+1,y+1}});
        }
        for(auto it:mpp){
            vector<int> tmp;
            for(auto it2:it.second){
                while(!it2.second.empty()){
                    tmp.push_back(*it2.second.begin());
                    it2.second.erase(it2.second.begin());
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};