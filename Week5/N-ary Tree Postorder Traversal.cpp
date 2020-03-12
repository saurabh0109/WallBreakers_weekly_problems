/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
            
            vector<int> nodelist;
            stack<Node*> s1,s2;
            
            if(root != nullptr)
                    s1.push(root);
            
            while(!s1.empty())
            {
                   Node* node = s1.top();
                   s1.pop();
                    
                   s2.push(node);
                   if(node->children.size() > 0 )
                   {
                           for(auto child : node->children)
                                   s1.push(child);
                   }                    
            }
            
            while(!s2.empty())
            {
                    Node* temp = s2.top();
                    s2.pop();
                    nodelist.push_back(temp->val);
            }
        
            return nodelist;
    }
};