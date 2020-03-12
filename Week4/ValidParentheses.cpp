class Solution {
public:
    bool isValid(string s) {
        
            stack<char> st;
            for(auto c : s)
            {
                    if(c == '(' || c == '{' || c == '[')
                            st.push(c);
                    else 
                    {
                            if(st.empty()) return false;
                            
                            switch(c)
                            {
                                    case ')': 
                                            if(st.top() == '(') st.pop();
                                            else
                                                    return false;
                                            break;
                                     case '}': 
                                            if(st.top() == '{') st.pop();
                                            else
                                                    return false;
                                            break;
                                     case ']': 
                                            if(st.top() == '[') st.pop();
                                            else
                                                    return false;
                                            break;
                                    default: return false;
                            }
                    }
            }
            
            return st.empty();
    }
};