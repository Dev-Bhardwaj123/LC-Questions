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
    long long kthLargestLevelSum(TreeNode* root, int k) {
       queue<TreeNode*> q;
        q.push(root);
        vector<long long> vec;
        int res=0;
        int cnt=0;
        while(q.empty()==false){
            cnt++;
            int count=q.size();
            long long sum=0;
            for(int i=0;i<count;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
                sum+=curr->val;
            }
            vec.push_back(sum);
        } 
        if(k>cnt){
            return -1;
        }
        sort(vec.begin(),vec.end());
        return vec[vec.size()-k];
    }
};