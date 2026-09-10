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
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                    vector<int>& postorder) {
        
        if (preorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        if (preorder.size() == 1)
            return root;

        int leftRoot = preorder[1];

        int index = 0;
        while (postorder[index] != leftRoot) {
            index++;
        }

        int leftSize = index + 1;

        vector<int> leftPre(preorder.begin() + 1,
                            preorder.begin() + 1 + leftSize);

        vector<int> rightPre(preorder.begin() + 1 + leftSize,
                             preorder.end());

        vector<int> leftPost(postorder.begin(),
                             postorder.begin() + leftSize);

        vector<int> rightPost(postorder.begin() + leftSize,
                              postorder.end() - 1);

        root->left = constructFromPrePost(leftPre, leftPost);
        root->right = constructFromPrePost(rightPre, rightPost);

        return root;
    }
};