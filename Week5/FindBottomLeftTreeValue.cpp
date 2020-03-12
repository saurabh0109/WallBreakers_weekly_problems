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
            
    int mlevel,value;    
    int findBottomLeftValue(TreeNode* root) {
           mlevel=0;  value=root->val;            
           getvalue(root,0);        
           return value;
    }
        
    void getvalue(TreeNode* root, int level)
    {
        if(root==nullptr) return;
        if(isLeaf(root) && level>mlevel){
                mlevel=level;
                value = root->val;
        }
        else{
                getvalue(root->left,level+1);
                getvalue(root->right,level+1);
        }
    }
        
    bool isLeaf(TreeNode* root){
         return (root->left==nullptr && root->right==nullptr);
    }
};