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
    int ans=-(1e9);
    int getans(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        else{
            int left=getans(root->left);
            int right=getans(root->right);
            int temp=root->val;
            ans=max(ans,temp);
            temp+=left;
            ans=max(ans,temp);
            temp=temp-left+right;
            ans=max(ans,temp);
            temp=root->val+left+right;
            ans=max(ans,temp);
            temp=max({0,root->val,root->val+left,root->val+right});
            return temp;
        }
    }
    int maxPathSum(TreeNode* root) {
        getans(root); 
        return ans;    
    }
};