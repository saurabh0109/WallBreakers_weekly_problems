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
    int sumOfLeftLeaves(TreeNode* root) {
     
            int sum=0;
            sumofLeft(root,false,sum);
            
            return sum;
    }
        
        void sumofLeft(TreeNode* node, bool isLeft, int& sum)
        {
                if(node == nullptr) return;
                if(isLeft && isLeaf(node)) {
                        sum+=node->val;
                        return ;                        
                }
                
                sumofLeft(node->left,true,sum);
                sumofLeft(node->right,false,sum);
        }
        
        bool isLeaf(TreeNode *root){
                return (root->left == nullptr && root->right==nullptr);
        }
};