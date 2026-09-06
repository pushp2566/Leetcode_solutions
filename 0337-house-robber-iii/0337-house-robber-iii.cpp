class Solution {
public:

    vector<int> solve(TreeNode* root) {

        if(root == NULL)
            return {0, 0};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        // Don't rob current node
        int notRob = max(left[0], left[1])
                   + max(right[0], right[1]);

        // Rob current node
        int rob = root->val
                + left[0]
                + right[0];

        return {notRob, rob};
    }

    int rob(TreeNode* root) {

        vector<int> ans = solve(root);

        return max(ans[0], ans[1]);
    }
};