class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
            if(strs.empty()) return "";
            string cprfx = "";
            
            int i=0, minStringlength = strs[0].length();
                       
            while(i<minStringlength)
            {
                    char c = strs[0][i];
                    for(auto s : strs)
                    {
                            if(c != s[i]) return cprfx;
                            if(i==0) minStringlength=min(minStringlength,(int)s.length());
                    }
                    
                    cprfx.append(1,c);
                    i++;
            }
            
            return cprfx;
    }
};