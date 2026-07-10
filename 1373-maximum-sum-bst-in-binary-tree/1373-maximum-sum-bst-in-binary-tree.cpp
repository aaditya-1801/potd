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
    struct Info {
        bool isBST;
        int mn, mx;
        int sum;
    };

    int ans = 0;

    Info dfs(TreeNode* root) {

        if (!root)
            return {true, INT_MAX, INT_MIN, 0};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST &&
            left.mx < root->val &&
            root->val < right.mn) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                min(root->val, left.mn),
                max(root->val, right.mx),
                currSum
            };
        }

        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {

        dfs(root);

        return ans;
    }
};