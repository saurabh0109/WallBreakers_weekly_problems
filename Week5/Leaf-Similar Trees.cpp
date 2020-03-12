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
 
    stack<TreeNode*> s;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            
            if(root1 == nullptr && root2 == nullptr)
                    return true;
            else if(root1 == nullptr)
                    return false;
            else if(root2 == nullptr)
                    return false;
            
            listLeafNodes(root1);
            
            return matchLeafNodes(root2);
            
        
    }
 
        void listLeafNodes(TreeNode* root)
        {
                if(root == nullptr)
                        return;
                if(root->left== nullptr && root->right==nullptr)
                        s.push(root);
                else
                {
                        listLeafNodes(root->left);
                        listLeafNodes(root->right);
                }                        
        }
        
        bool matchLeafNodes(TreeNode* root)
        {
                if(root == nullptr)
                        return true;
                if(root->left== nullptr && root->right==nullptr)
                {
                        if(!s.empty() && root->val == s.top()->val)
                        {
                                s.pop();
                                return true;
                        }
                        else
                                return false;
                }
                else                
                        return matchLeafNodes(root->right) && matchLeafNodes(root->left);                              
        }
        
};