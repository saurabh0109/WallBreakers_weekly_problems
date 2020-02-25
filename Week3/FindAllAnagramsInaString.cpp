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


// ***********************************
// Sorting solution (TLE) 
// ***********************************
/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
           vector<int> idxs;
           if(s.empty() || s.length() < p.length()) return idxs;
            
           sort(p.begin(),p.end());
           
           for(int i=0;i<=s.length()-p.length();i++){
                   
                   string str = s.substr(i,p.length());
                   sort(str.begin(),str.end());
                   
                   if(str.compare(p) == 0) idxs.push_back(i);
           }
           
           return idxs;
    }
        
    
};*/