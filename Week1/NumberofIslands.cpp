class Solution {
public:

    int m, n;
        
    int numIslands(vector<vector<char>>& grid) {
        
           int count = 0;
           if(grid.empty()) return count;
           m = grid.size();
           n = grid[0].size();
            
           for(int i=0;i<m;i++)
           {
                   for(int j=0;j<n;j++)
                   {
                           if(grid[i][j] == '1')
                           {
                                   count++;
                                   isIslandUtil(grid,i,j);
                           }                                        
                   }
           }
            
           return count;
    }
        
      void isIslandUtil(vector<vector<char>>& grid, int i, int j)
      {
           grid[i][j] = '2';
              
           if(isSafe(i+1,j) && grid[i+1][j] == '1')   
              isIslandUtil(grid,i+1,j);
           if(isSafe(i,j+1) && grid[i][j+1] == '1')   
              isIslandUtil(grid,i,j+1);
           if(isSafe(i-1,j) && grid[i-1][j] == '1')   
              isIslandUtil(grid,i-1,j);
           if(isSafe(i,j-1) && grid[i][j-1] == '1')   
              isIslandUtil(grid,i,j-1);                                  
      }
     
     bool isSafe(int i, int j){
         return ( (i<m && i>=0) && (j<n && j>=0));
     }
};