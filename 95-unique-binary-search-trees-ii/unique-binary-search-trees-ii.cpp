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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};

        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;

        // No values in this range
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        // Try every value as root
        for (int root = start; root <= end; root++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees = build(start, root - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees = build(root + 1, end);

            // Combine every left subtree with every right subtree
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* node = new TreeNode(root);

                    node->left = left;
                    node->right = right;

                    result.push_back(node);
                }
            }
        }

        return result;
    }
};