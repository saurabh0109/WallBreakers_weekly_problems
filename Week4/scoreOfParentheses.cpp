class Solution {
public:
    int scoreOfParentheses(string S) {
     
            if(S.empty()) return 0; 
            stack<string> st;
            int score=0;
            
            for(auto s : S)
            {
                    string str(1,s);
                    if(s == '(') st.push(str);                    
                    else if(s == ')')
                    {
                           int curscore=0;
                           bool doProcess = true;
                           while(doProcess && !st.empty())
                           { 
                                    string t = st.top(); 
                                    if(t == "(")
                                    {          
                                            if(curscore == 0) curscore=1;
                                            else curscore*=2;
                                            st.pop();
                                            st.push(to_string(curscore));
                                            doProcess = false;
                                    }
                                    else if(isdigit(t[0]))
                                    {
                                            curscore+=stoi(t);
                                            st.pop();
                                    }
                           }                            
                    }
            }
            
            while(!st.empty()){
                    score+=stoi(st.top());
                    st.pop();
            }
            
            return score;
    }
};