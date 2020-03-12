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
    unordered_map<int,vector<TreeNode*>> memo;    
    vector<TreeNode*> allPossibleFBT(int N) 
    {
            if(memo.find(N) != memo.end()) return memo[N];
            if(N%2==0) return {};             
            if(N==1)  return { new TreeNode(0)};
            vector<TreeNode*> res;    
            
            for(int i=1;i<N;i+=2)
            {
                    for(auto left : allPossibleFBT(i))
                    {
                            for( auto right : allPossibleFBT(N-i-1))
                            {
                                    TreeNode* root = new TreeNode(0);
                                    root->left = left;
                                    root->right = right;
                                    res.push_back(root);
                            }
                    }
            }
            
            memo[N]= res;
            return res;
    }                
};