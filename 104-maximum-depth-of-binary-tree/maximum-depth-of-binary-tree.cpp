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
//  void postorder(TreeNode* root,vector<int>&arr){
//       if(root==NULL) return;
//     postorder(root->left,arr);
     
//       postorder(root->right,arr);
//        arr.push_back(root->val);
//    }

int solve(TreeNode* root){
    if(root == NULL)return  0 ;

    int l=solve(root->left);
    int r=solve(root->right);

    return 1+max(l,r);
}
    int maxDepth(TreeNode* root) {
        

        return solve(root);

    

    }
};