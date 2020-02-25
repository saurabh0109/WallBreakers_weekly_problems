class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
            
            if(s.empty() || g.empty()) return 0;
            
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            
            int i=0,j=0, c=0;
            while(i<g.size() && j<s.size()){
                    if(s[j] >= g[i]){
                            c++;
                            i++;
                    }                    
                    j++;
            }
            
            return c;
        
    }
};