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
    long long max_Product=0;
    int totalSum=0;
    const int MOD=1e9+7;

    void getTotalSum(TreeNode* root){
        //Base case
        if(root==NULL) return;
        totalSum+=root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
    }

    long long dfs(TreeNode* root){
        if(root==NULL) return 0;

        long long leftSubtreeSum=dfs(root->left);
        long long rightSubtreeSum=dfs(root->right);

        long long subtreeSum=leftSubtreeSum+rightSubtreeSum+root->val;

        long long product=subtreeSum*(totalSum-subtreeSum);

        max_Product=max(product,max_Product);

        return subtreeSum;

    }




    int maxProduct(TreeNode* root) {
        getTotalSum(root);
        dfs(root);
        return max_Product%MOD;
        
    }
};