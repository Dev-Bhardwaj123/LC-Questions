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
    vector<int> ans;
    map<TreeNode*,TreeNode*> parent;
    set<TreeNode*> vis;

    void findParent(TreeNode* root){
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr){
            parent[root->left]=root;
            findParent(root->left);
        }
        if(root->right!=nullptr){
            parent[root->right]=root;
            findParent(root->right);
        }
    }

    void dfs(TreeNode* root, int k){
        if(vis.find(root)!=vis.end()){
            return;
        }
        vis.insert(root);
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(root->left!=nullptr){
            dfs(root->left,k-1);
        }
        if(root->right!=nullptr){
            dfs(root->right,k-1);
        }
        TreeNode* p=parent[root];
        if(p!=nullptr){
            dfs(p,k-1);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        findParent(root);
        dfs(target,k);
        return ans;
    }
};