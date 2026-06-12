/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root,vector<TreeNode*>& ans, int x){
        if(root==nullptr){
            return false;
        }
        ans.push_back(root);
        if(root->val==x){
            return true;
        }
        if(getPath(root->left,ans,x) || getPath(root->right,ans,x)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> res1;
        vector<TreeNode*> res2;
        getPath(root,res1,p->val);
        getPath(root,res2,q->val);
        TreeNode* res=root;
        int sz=min(res1.size(),res2.size());
        for(int i=0;i<sz;i++){
            if(res1[i]==res2[i]){
                res=res1[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};