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
    int preIndex=0;
    TreeNode* constBTree(vector<int>& pre,vector<int>& inorder,int is,int ie){
        if(is>ie){
            return nullptr;
        }
        TreeNode* root=new TreeNode(pre[preIndex++]);
        int inIndex;
        for(int i=0;i<pre.size();i++){
            if(inorder[i]==root->val){
                inIndex=i;
                break;
            }
        }
        root->left=constBTree(pre,inorder,is,inIndex-1);
        root->right=constBTree(pre,inorder,inIndex+1,ie);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> pre=preorder;
        sort(preorder.begin(),preorder.end());
        vector<int> inorder=preorder;
        return constBTree(pre,inorder,0,pre.size()-1);
    }
};