class Solution {
public:
    bool isIsomorphic(string s, string t) {        
           if(s.length() != t.length()) return false;            
           unordered_map<char,char> cm;
           unordered_set<char> mcs;
           
           for(int i=0;i<s.length();i++)
           {
                   if(cm.find(s[i]) == cm.end())  
                   {
                           if (mcs.find(t[i]) != mcs.end()) 
                                return false;                   
                           
                           mcs.insert(t[i]);
                           cm[s[i]] = t[i];                           
                   }
                   else if (cm[s[i]] != t[i]) 
                           return false;                   
           }            
           return true; 
    }
};