/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans=0;
    int depth(TreeNode* root){
        if(root==NULL)return 0;
        int left=0;
        int right=0;
        left=fun(root->left);
        right=fun(root->right);
        
        ans=max(ans,left+right+1);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        if(ans==0){
            return 0;
        }
        return ans-1;
    }
};