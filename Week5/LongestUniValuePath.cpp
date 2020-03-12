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
    
    int maxp;
    int longestUnivaluePath(TreeNode* root) {
      if(root == nullptr || isLeaf(root)) return 0;
      maxp=0;      
      longestPath(root);
      
      return maxp;      
    }
  
  int longestPath(TreeNode* root)
  {
    if(root == nullptr) return 0;    
    int left = longestPath(root->left);
    int right = longestPath(root->right);
          
    int lleft = 0, lright=0;
    if(root->left != nullptr && root->val == root->left->val)
       lleft += left+1;
    if(root->right != nullptr && root->val == root->right->val)
       lright += right+1;
    
    maxp = max(maxp,lleft+lright);      
    return max(lleft,lright);
  }
    
  
   bool isLeaf(TreeNode* root){
     return (root->left == nullptr &&  root->right==nullptr);
   }
};