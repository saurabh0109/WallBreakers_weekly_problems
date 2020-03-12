class Solution {
public:    
    vector<string> generateParenthesis(int n) {                        
            vector<string> res;            
            string s; s.append(2*n,'.');
            parenthesisUtil(0,2*n,s,n,n,res);            
            return res;                    
    }
        
       void  parenthesisUtil(int idx, int n, string& s, int i, int j, vector<string>& res)
       {                               
                if(idx==n){                        
                        res.push_back(s);
                        return;
                }
                
                if(i<j){
                        s[idx]=')';
                        parenthesisUtil(idx+1,n,s,i,j-1,res);                
                }
                
                if(i>0){
                        s[idx]='(';
                        parenthesisUtil(idx+1,n,s,i-1,j,res);
                }                
        }
};