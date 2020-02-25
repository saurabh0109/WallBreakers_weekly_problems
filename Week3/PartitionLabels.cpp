class Solution {
public:
    vector<int> partitionLabels(string S) {        
           if(S.empty()) return {};
           
            vector<int> p;
           map<char,int> m;
           for(int i=0;i<S.length();i++)
                   m[S[i]]=i;
            
           int st=0, end=0, i=0;  
           while( i < S.length()){
                   end = max(end,m[S[i]]);
                   if(i==end){
                           p.push_back(end-st + 1);
                           st = i+1;                           
                   }                
                   i++;
           }       
           return p; 
    }
};