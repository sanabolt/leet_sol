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
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (root == NULL)
            return;

        // Add current node
        if (path.empty())
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // If leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Go left
        dfs(root->left, path, ans);

        // Go right
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        dfs(root, "", ans);

        return ans;
    }
};