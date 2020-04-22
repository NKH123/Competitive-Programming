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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode* root=new TreeNode()
        root->val=preorder[0];
        root->left=NULL;
        root->right=NULL;
        vector<int>left;
        vector<int>right;
        for(int i=1;i<preorder.size();i++){
            if(preorder[i]<preorder[0]){
                left.push_back(preorder[i]);
            }
            else{
                right.push_back(preorder[i]);
            }
        }
        root->left=bstFromPreorder(left);
        root->right=bstFromPreorder(right);
        return root;        
        
    }
};