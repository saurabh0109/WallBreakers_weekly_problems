

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
       if(paragraph.empty()) return paragraph;
       unordered_set<string> bw; 
       unordered_map<string,int> wmap;        
       for(auto b : banned) bw.insert(b);
      
       int maxcount=0;             
       string w, mfw;
            
       for(auto c : paragraph)
       {
                if(isalpha(c)) w.append(1,tolower(c));
                else if (!w.empty()){                                              
                       if(bw.find(w) == bw.end()){
                                wmap[w]++;
                                if(maxcount < wmap[w]){
                                        mfw = w;
                                        maxcount = wmap[w];
                                }     
                       }
                       w.clear();               
                }               
        }               
        
       if(!w.empty() && bw.find(w) == bw.end()){
                wmap[w]++;
                if(maxcount < wmap[w]){
                        mfw = w;
                        maxcount = wmap[w];
                }     
       }       
        
        return mfw;
    }        
};