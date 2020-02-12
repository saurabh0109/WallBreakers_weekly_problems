class Solution {
public:
    string reverseVowels(string s) {
        
            if(s.length() <=1) return s;
            int i=0, j=s.length()-1;
            while(i<j)
            {
                   if(isVowel(s[i]) && isVowel(s[j]))
                           swap(s[i++],s[j--]);
                   else if(!isVowel(s[i]))i++;
                   else if(!isVowel(s[j]))j--;
            }            
            return s;
    }
        
     bool isVowel(char c){
             c = tolower(c);
             if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
                     return true;             
             return false;
     }
};