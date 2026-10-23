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
    TreeNode* build(vector<int>& preorder,int &ind,int upp){
        if(ind >= preorder.size() || preorder[ind] > upp)return NULL;
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = build(preorder,ind,root->val);
        root->right = build(preorder,ind,upp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return build(preorder,ind,INT_MAX);
    }
};