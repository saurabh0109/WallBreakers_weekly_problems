class Solution {
public:
    bool wordPattern(string pattern, string str) {
            
            if(pattern.empty() || str.empty()) return false;
            
            unordered_map<char,string> hash; 
            unordered_set<string> s;
            stringstream ss(str);
            string word;
            int idx=0, n = pattern.length();
            
            while(getline(ss,word,' '))
            {
                    if(hash.find(pattern[idx]) == hash.end())
                    {
                            if(s.find(word) != s.end()) return false;
                            hash.insert(pair<char,string>(pattern[idx],word));
                            s.insert(word);
                    }
                    else if(hash[pattern[idx]] != word) 
                            return false;
                    
                    idx++;
            }
            
            return (idx==n);
    }
};