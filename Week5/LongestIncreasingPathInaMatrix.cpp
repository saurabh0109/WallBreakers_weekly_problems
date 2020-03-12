class Solution {
public:
    int m,n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      
      if(matrix.empty()) return 0;
      int result=0; 
      m = matrix.size();
      n = matrix[0].size();
      vector<vector<int>> dp(m,vector<int>(n,-1));
      
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++){
          if(dp[i][j]<0)
            lip(matrix,i,j,dp);
          
          result= max(result,dp[i][j]);
        }
      }      
      return result; 
    }
  
     int lip(vector<vector<int>>& matrix, int i , int j, vector<vector<int>>& dp)
     {
       if(IsSafe(i,j) == false) return 0;
       
       if(dp[i][j]>=0) return dp[i][j];
       
       vector<int> adjx = {-1,1,0,0} , adjy = {0,0,-1,1};
              
       int _lip = 1; 
       for(int k=0;k<4;k++){
         int x=i+adjx[k], y=j+adjy[k];     
         if(IsSafe(x,y) && matrix[i][j] < matrix[x][y])
         _lip = max(_lip,1+lip(matrix,x,y,dp)); 
       }
       
       return dp[i][j] = _lip;       
     }
  
     bool IsSafe(int i, int j){
       return (i>=0 && i<m && j>=0 && j<n);
     }
};