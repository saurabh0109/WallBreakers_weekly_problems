class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
            if(board.empty()) return;            
            int r = board.size(), c = board[0].size();
            
            for(int j=0;j<c;j++){
                    if(board[0][j] == 'O') findConnectedBorderOs(board,0,j);
                    if(board[r-1][j] == 'O') findConnectedBorderOs(board,r-1,j);
            }
            
            for(int i=1;i<r-1;i++){
                    if(board[i][0] == 'O') findConnectedBorderOs(board,i,0);
                    if(board[i][c-1] == 'O') findConnectedBorderOs(board,i,c-1);
            }
                                                            
            Convert(board);
            
    }        
        
    void findConnectedBorderOs(vector<vector<char>>& board, int i, int j){
            
            board[i][j] = '#';            
            int adjX[] = {-1,0,1,0};
            int adjY[] = {0,1, 0,-1};
            int r = board.size(), c = board[0].size();
            
            for(int k=0;k<4;k++)
            {
                    int x = i+adjX[k], y = j+adjY[k];
                    if(isSafe(r,c,x,y) && board[x][y] == 'O') 
                            findConnectedBorderOs(board,x,y);
            }            
    }
        
    bool isSafe(int r, int c, int i, int j){
            return (i>=0 && i<r && j>=0 && j<c);
    }

    void Convert(vector<vector<char>>& board)
    {
         int r = board.size(), c = board[0].size();
         for(int i=0;i<r;i++){
                 for(int j=0;j<c;j++){
                         if(board[i][j] == 'O') board[i][j]='X';
                         else if(board[i][j] == '#') board[i][j] = 'O';
                 }
         }   
           
    }
};
};