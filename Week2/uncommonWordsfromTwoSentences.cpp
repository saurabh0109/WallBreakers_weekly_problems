class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
            
            vector<string> res;
            map<string,int> wmapA, wmapB; 
            populatewordMap(wmapA,A);
            populatewordMap(wmapB,B);
            
            for(auto w : wmapA){
                    if(w.second == 1 && wmapB.find(w.first) == wmapB.end())
                            res.push_back(w.first);
            }
            
             for(auto w : wmapB){
                    if(w.second == 1 && wmapA.find(w.first) == wmapA.end())
                            res.push_back(w.first);
            }
            return res;
    }
        
  void populatewordMap(map<string,int>& wmap, string s)
  {          
            string w;
            for(auto c: s){
                   if(isalpha(c)) w.append(1,c);
                   else if(!w.empty()){
                           wmap[w]++;
                           w.clear();
                   }
            }
            if(!w.empty()) wmap[w]++;
  }
};