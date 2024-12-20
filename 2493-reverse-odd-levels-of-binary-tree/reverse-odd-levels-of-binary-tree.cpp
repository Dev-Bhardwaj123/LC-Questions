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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int lvl = 0;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> nodes;
            queue<TreeNode*> temp = q;
            for (int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                if (it->left) q.push(it->left);
                if (it->right) q.push(it->right);
                nodes.push_back(it->val);
            }
            if (lvl % 2 != 0) {
                reverse(nodes.begin(), nodes.end());
                int i = 0;
                while (size--) {
                    auto it = temp.front();
                    temp.pop();
                    it->val = nodes[i];
                    i++;
                }
            }
            lvl++;
        }
        return root;
    }
};