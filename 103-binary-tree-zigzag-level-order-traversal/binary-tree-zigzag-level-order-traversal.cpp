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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        stack<int> st;
        q.push(root);
        bool rev=false;
        while(!q.empty()){
            vector<int> res;
            int c=q.size();
            for(int i=0;i<c;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(!rev){
                    res.push_back(curr->val);
                }
                else{
                    st.push(curr->val);
                }
                if(curr->left!=nullptr){
                    q.push(curr->left);
               }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }
            rev=!rev;
            ans.push_back(res);

        }
        return ans;
    }
};