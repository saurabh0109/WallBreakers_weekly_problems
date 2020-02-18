class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
     
        string morsemap[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};    
            
        set<string> txfms;
        for(auto c : words){
                string str;
                for(int i=0;i<c.length();i++){
                        str += morsemap[c[i] -'a'];
                }        
                txfms.insert(str);
        }
            
        return txfms.size();
    }
};