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
    int postIndex;
    TreeNode* cTree(vector<int>& inorder, vector<int>& postorder,int is,int ie){
        if(is>ie){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[postIndex--]); //picking main root from postOrder as post[n-1]=root
        int inIndex; //finding same val of root in inOrder arr
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){  //searching root in inOrder
                inIndex=i;
                break;
            }
        } 
        root->right=cTree(inorder,postorder,inIndex+1,ie); //right subtree formation
        root->left=cTree(inorder,postorder,is,inIndex-1); //left subtree formation
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex=postorder.size()-1;
        return cTree(inorder,postorder,0,inorder.size()-1);
    }
};