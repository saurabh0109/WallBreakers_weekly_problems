class Solution {
public:
    string reverseWords(string s) {
            
            int st=0;            
            for(int i=0;i<s.length();i++)
                   if(s[i] == ' ') {
                           reverse(s,st,i-1);                
                           
                           while(s[i] == ' ') i++;
                           st = i;
                   }
            
            if(st!=s.length()-1) reverse(s,st,s.length()-1);
            return s;
    }
        
     void reverse(string& s, int st, int end){
             while(st<end){
                     char c= s[st];
                     s[st++] = s[end];
                     s[end--] = c;
             }
     }
};