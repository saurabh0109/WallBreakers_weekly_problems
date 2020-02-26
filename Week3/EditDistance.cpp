class Solution {
public:
    int mem[501][501];    
                         
    int minDistance(string word1, string word2) {
        
        int m = word1.length(), n = word2.length();    
        if(m==0 || n==0)
                return m+n;
          
        for(int i=0;i<m+1;i++)
                for(int j=0;j<n+1;j++)
                        mem[i][j]=-1;                    
              
        return util(word1,word2,m,n);                        
    }
        
    int util(string w1, string w2, int i, int j){
            
            if(mem[i][j] != -1) return mem[i][j];
            
            if(i==0 || j==0)
                    mem[i][j] = i+j;                                               
            else if(w1[i-1] == w2[j-1])
                    mem[i][j] = util(w1,w2,i-1,j-1);            
            else 
                    mem[i][j] = 1 + min( min(util(w1,w2,i,j-1),
                                util(w1,w2,i-1,j)), 
                                util(w1,w2,i-1,j-1));            
            return mem[i][j];            
    }    
};
