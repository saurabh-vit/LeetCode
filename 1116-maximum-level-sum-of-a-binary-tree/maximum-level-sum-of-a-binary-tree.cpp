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
    //Apporach 1:- BFS
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;

        int ans = 0;
        int maxSum = INT_MIN;

        q.push({root, 1});

        while(q.size() > 0) {
            int currLevelSize = q.size();
            int sum = 0;
            int currLevel = 0;

            for(int i = 0; i < currLevelSize; i++) { //CURR Level Process At A time TO Calculate SUM
                TreeNode *curr = q.front().first;
                int level = q.front().second;
                currLevel = level;
                q.pop();

                sum += curr->val;

                if(curr->left != NULL) {
                    q.push({curr->left, level + 1});
                }

                if(curr->right != NULL) {
                    q.push({curr->right, level + 1});
                }
            }

            if(sum > maxSum) {
                maxSum = sum;
                ans = currLevel; 
            }
        }

        return ans;
    }
};