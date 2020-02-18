class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
            vector<int> idxs;
            if(s.length() < p.length()) return idxs;
            int sm[26] = {0} ,pm[26] = {0};
            
            for(int i=0;i<p.length();i++)
            {
                    sm[s[i] - 'a']++;
                    pm[p[i] - 'a']++;
            }
            
            for(int i=p.length();i<s.length();i++)
            {
                    if(isSimilar(sm,pm) == true) 
                            idxs.push_back(i-p.length());                    
                    
                    sm[s[i] - 'a']++;
                    sm[s[i-p.length()] - 'a']--;                    
            }
            
            if(isSimilar(sm,pm) == true) 
                    idxs.push_back(s.length()-p.length());
            
            return idxs;
    }
        
    bool isSimilar(int sm[], int pm[])
    {                        
            for(int i=0;i<26;i++)
                    if(sm[i]!=pm[i]) return false;
            return true;
    }
};