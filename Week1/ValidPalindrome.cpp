class Solution {
public:
    bool isPalindrome(string str) {
        
           string s;
           for(auto c : str)
           {
                if((c >= 'a' && c <='z') || (c >= '0' && c<='9') || (c >='A' && c<='Z')  )
                  s.append(1,c);              
           }
           transform(s.begin(), s.end(), s.begin(), ::tolower); 
           
            string c = s;
            reverse(c.begin(),c.end());
                    
            if(s.compare(c) == 0) return true;
            else return false;                                                   
    }
};