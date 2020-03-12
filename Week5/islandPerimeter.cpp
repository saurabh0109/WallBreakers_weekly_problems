class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
            if(grid.empty()) return 0;
            vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
            
            for(int i=0;i<grid.size();i++)
                    for(int j=0;j<grid[0].size();j++)
                            if(grid[i][j] == 1)
                                    return findPerimeter(grid,i,j,visited);
            
            return 0;
    }
        
     int findPerimeter(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited)
     {
             visited[i][j]=true;
             
             int m=grid.size(), n = grid[0].size();
             int perimeter = 0;
             vector<int> adjr = {-1, 1, 0, 0};
             vector<int> adjc = {0, 0, -1, 1};
             
             int adjIslandCells = 0;
             for(int k=0;k<4;k++){
                     int x = i+adjr[k], y = j+adjc[k];
                     if(isSafe(m,n,x,y) && grid[x][y] == 1) 
                             adjIslandCells++;
             }
             
             perimeter =  4 - adjIslandCells; 
             
             for(int k=0;k<4;k++)
             {
                     int x = i+adjr[k], y = j+adjc[k];
                     if(isSafe(m,n,x,y) && grid[x][y] == 1 && visited[x][y] == false)
                             perimeter+= findPerimeter(grid, x , y,visited);
             }
             
             return perimeter;
     }   
        
     bool isSafe(int m, int n , int i, int j){
             return (i>=0 && i<m && j>=0 && j<n);
     }   
};