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
    int diameterOfBinaryTree(TreeNode* root) {
            
            if(root == nullptr) return 0;                       
            int h=0;
            return diameterUtil(root,h)-1;      
    }
        
      int diameterUtil(TreeNode* root, int& height){
              if(root == nullptr) return 0;
              int lh=0,rh=0, ld=0,rd=0;
              
              ld = diameterUtil(root->left,lh);
              rd = diameterUtil(root->right,rh);
              
              height = 1 + max(lh,rh);
              return max(lh+rh+1,max(ld,rd));             
      }
};