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
        if(root==nullptr){
            return ans;
        }
        map<int,vector<pair<int,int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            TreeNode* curr=it.first;
            int line=it.second.first;
            int lvl=it.second.second;
            q.pop();
            mp[line].emplace_back(lvl,curr->val);
            if(curr->left!=nullptr){
                q.push({curr->left,{line-1,lvl+1}});
            }
            if(curr->right!=nullptr){
                q.push({curr->right,{line+1,lvl+1}});
            }
        }
        for(auto& m:mp){
            vector<int> lev;
            sort(m.second.begin(),m.second.end());
            for(auto& p:m.second){
                lev.push_back(p.second);
            }
            ans.push_back(lev);
        }
        return ans;
    }
};