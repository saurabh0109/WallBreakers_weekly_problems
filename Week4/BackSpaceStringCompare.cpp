class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
            stack<char> s,t;
            
            for(auto str: S){
                    if(str == '#'){
                       if(!s.empty()) 
                        s.pop();
                    }
                    else s.push(str);
            }
            
             for(auto str: T){
                    if(str == '#'){
                      if(!t.empty()) 
                          t.pop();      
                    } 
                    else t.push(str);
            }
            
            while(!s.empty() && !t.empty()){
                    if(s.top() != t.top()) return false;
                    s.pop();
                    t.pop();
            }
            
            if(!s.empty() || !t.empty()) return false;
            return true;
    }
};