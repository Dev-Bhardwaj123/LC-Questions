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
    bool check(TreeNode* root, long minVal,long maxVal){
        if(root==nullptr){
            return true;
        }
        if(root->val>=maxVal || root->val<=minVal) return false;
        return check(root->left,minVal,root->val) && check(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        long maxi = LONG_MAX;
        long mini = LONG_MIN;
        return check(root,mini,maxi);
    }
};