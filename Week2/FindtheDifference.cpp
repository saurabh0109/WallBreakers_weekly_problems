class Solution {
public:
    char findTheDifference(string s, string t) {
        
            int i=0, charmap[26] = {0};
            while(i<s.length()){
                    charmap[s[i]-'a']++;
                    charmap[t[i]-'a']--;
                    i++;
            }
            charmap[t[i]-'a']--;
            
            for(int i=0;i<26;i++)
                    if (charmap[i] < 0) return 'a' + i;
            
            return 'a';
    }
};