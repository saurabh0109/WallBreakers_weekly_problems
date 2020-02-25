class Solution {
public:
    bool isAnagram(string s, string t) {
        
            if(s.length() != t.length()) return false;
            
            if(s.empty()) return true; 
            
            int a[26] = {0};
            
            for(int i=0;i<s.length();i++)
            {
                    a[s[i]-'a']++;
                    a[t[i]-'a']--;
            }
                    
            for(auto i : a)
                    if(i!=0) return false;
            
            return true;
    }
};