class Solution {
public:
    int firstUniqChar(string s) {
            
            int charMap[26] = {0};
            
            for(auto c: s) charMap[c-'a']++;
         
            for(int i=0;i<s.length();i++){
                    if(charMap[s[i]-'a'] == 1) return i;
            }
            
            return -1;        
    }
};