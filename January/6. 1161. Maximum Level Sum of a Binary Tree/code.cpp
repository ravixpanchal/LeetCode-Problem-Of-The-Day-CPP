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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;


        //BFS Implementation
        queue<TreeNode*>q;

        q.push(root);

       int maxSum=INT_MIN;
       int maxLevel=1;
       int currLevel=1;



        while(!q.empty()){
            int levelSize=q.size();

            int levelSum=0;

            for(int i=0;i<levelSize;i++){
                TreeNode* currNode=q.front();
                q.pop();

                levelSum+=currNode->val;

                if(currNode->left!=NULL){
                    q.push(currNode->left);
                }

                if(currNode->right!=NULL){
                    q.push(currNode->right);
                }
            }

            if(levelSum>maxSum){
                maxSum=levelSum;
                maxLevel=currLevel;
            }
            currLevel++;

        }

        return maxLevel;
        
    }
};