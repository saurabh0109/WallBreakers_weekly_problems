class Solution {
public:      
                         
    int minDistance(string word1, string word2) {
        
        int m = word1.length(), n = word2.length();    
        if(m==0 || n==0)
                return m+n;                   
              
        return util(word1,word2,m,n);                        
    }
        
    int util(string w1, string w2, int m, int n){
            
            int dp[m+1][n+1];                
            
            for(int i=0;i<m+1;i++){
                for(int j=0;j<n+1;j++){
                        if(i==0 || j==0)
                                dp[i][j] = i+j;      
                        else if(w1[i-1] == w2[j-1])
                                dp[i][j] = dp[i-1][j-1];            
                        else 
                                dp[i][j] = 1 + min( min(dp[i][j-1],
                                                         dp[i-1][j]), 
                                                         dp[i-1][j-1]);
                    }
            }
                                                         
            return dp[m][n];            
    }    
};
