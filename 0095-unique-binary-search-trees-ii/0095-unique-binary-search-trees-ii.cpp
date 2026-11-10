class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};

        return solve(1, n);
    }

    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }

        for (int i = start; i <= end; i++) {

            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);

            for (auto l : left) {
                for (auto r : right) {

                    TreeNode* root = new TreeNode(i);

                    root->left = l;
                    root->right = r;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};