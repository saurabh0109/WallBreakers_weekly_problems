class Solution {
public:
    int calPoints(vector<string>& ops) {        
            if(ops.empty()) return 0;   
            
            stack<int> st;
            map<string,int> pmap;
            pmap["+"]=1001; 
            pmap["D"]=1002;
            pmap["C"]=1003;            
            
            for(auto str : ops){  
                    int s;
                    if(pmap.find(str) != pmap.end()) 
                            s = pmap[str];
                    else 
                            s = stoi(str);
                  
                    ProcessInput(s,st);
            }
            
            int sum=0;
            while(!st.empty()){
                    sum+=st.top();
                    st.pop();
            }            
            return sum;
    }
        
    void ProcessInput(int s, stack<int>& st){            
            switch(s)
            {                            
                    case 1001: 
                    {
                            if(st.size() < 2 ) break; 
                            int top = st.top(); 
                            st.pop();
                            int t2 = st.top(); 
                            st.push(top);
                            st.push(top+t2);
                            break; 
                    }
                    case 1002: 
                    {
                            if(st.size() < 1) break;
                            st.push(st.top()*2);
                            break;
                    }
                    case 1003: 
                    {
                            if(st.size() < 1) break;
                            st.pop(); 
                            break;
                    }
                    default:
                            st.push(s);
            }
    }
};