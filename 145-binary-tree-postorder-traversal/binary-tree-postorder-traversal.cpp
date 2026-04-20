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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> stack1, stack2;
        stack1.push(root);

        while (!stack1.empty()) {
            TreeNode* current = stack1.top();
            stack1.pop();
            stack2.push(current);

            if (current->left) {
                stack1.push(current->left);
            }
            if (current->right) {
                stack1.push(current->right);
            }
        }

        vector<int> result;
        while (!stack2.empty()) {
            result.push_back(stack2.top()->val);
            stack2.pop();
        }

        return result;
    }
};