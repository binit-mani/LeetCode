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
class BSTI{
public:
    stack<TreeNode*> myStack;
    bool reverse;
    BSTI(TreeNode* root,bool r){
        reverse = r;
        if(!r) pushAll(root);
        else pushAll(root);
    }
    int next(){
        TreeNode* node = myStack.top();myStack.pop();
        if(reverse)pushAll(node->left);
        else pushAll(node->right);
        return node->val;
    }
    void pushAll(TreeNode* root){
        if(reverse){
            while(root){
                myStack.push(root);root = root->right;
            }
        }
        else {
            while(root){
                myStack.push(root);root = root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTI pre(root,false);
        BSTI pos(root,true);
        int i = pre.next();
        int j = pos.next();
        while(i<j){
            if(i+j == k)return true;
            if(i+j < k)i = pre.next();
            else j = pos.next();
        }
        return false;
    }
};