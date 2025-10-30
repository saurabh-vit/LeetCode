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
    int maxSum = INT_MIN;

    int findMaxGain(TreeNode* root) {
        if (!root) return 0;
        int leftGain = max(0, findMaxGain(root->left));
        int rightGain = max(0, findMaxGain(root->right));
        maxSum = max(maxSum, leftGain + rightGain + root->val);
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        findMaxGain(root);
        return maxSum;
    }
};