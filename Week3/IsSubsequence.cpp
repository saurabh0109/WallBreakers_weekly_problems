class Solution {
public:
    bool isSubsequence(string s, string t) {
                    
            if(t.empty() || s.empty()) return s.empty();            
            
            if(s.length() == t.length()) return (s.compare(t) == 0) ? true : false;
            
            int i=0,j=0;
            
            while(i<s.length() && j<t.length()){                    
                    if(t[j] == s[i]) i++;                            
                    j++;
            }
            
            return ( i == s.length());
    }
};