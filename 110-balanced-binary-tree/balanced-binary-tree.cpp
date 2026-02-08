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
    int getKnow(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = getKnow(root->left);
        int right = getKnow(root->right);

        if(abs(right-left)<=1){
            return max(left, right)+1; 
        }
        return 1e5;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int val = getKnow(root);
        if(val>=1e5) return false;
         return true;
        
    }
};