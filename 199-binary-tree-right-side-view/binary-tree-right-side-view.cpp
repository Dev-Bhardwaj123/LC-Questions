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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty()){
            int cnt=q.size();
            for(int i=0;i<cnt;i++){
                TreeNode* curr=q.front();
                 q.pop();
                if(i==cnt-1){
                    temp.push_back(curr->val);
                }
            
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return temp;
    }
};