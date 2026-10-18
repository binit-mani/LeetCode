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
 using ll = long long;
class Solution {
public:
    ll widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        while(!q.empty()){
            ll size = q.size();
            ll mini = q.front().second;
            ll mini_l=0,maxi_l = 0;
            for(ll i=0;i<size;i++){
                TreeNode* tmp = q.front().first;
                ll ind = q.front().second-mini;
                if(i == 0)mini_l = ind;
                if(i == size-1)maxi_l = ind;
                if(tmp->left){
                    q.push({tmp->left,2*ind+1});
                }
                if(tmp->right){
                    q.push({tmp->right,2*ind+2});
                }
                q.pop();
            }
            ans = max(ans,maxi_l-mini_l+1);
        }
        return (int)ans;
    }
};