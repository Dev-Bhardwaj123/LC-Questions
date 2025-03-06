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
    int cam = 0;

    int dfs(TreeNode* node) {
        if (!node) return 2; // A null node is considered covered.

        int left = dfs(node->left);
        int right = dfs(node->right);

        // If any child is not covered, place a camera at this node
        if (left == 0 || right == 0) {
            cam++;
            return 1; // This node has a camera
        }

        // If any child has a camera, this node is covered
        if (left == 1 || right == 1) return 2;

        // Otherwise, this node is not covered
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cam++; // If the root itself is not covered, place a camera.
        return cam;
    }
};
