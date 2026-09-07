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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if (nums.empty())
            return nullptr;

        // Find index of maximum element
        int maxIndex = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Create root using maximum element
        TreeNode* root = new TreeNode(nums[maxIndex]);

        // Create left subtree
        vector<int> left(nums.begin(), nums.begin() + maxIndex);

        // Create right subtree
        vector<int> right(nums.begin() + maxIndex + 1, nums.end());

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
};