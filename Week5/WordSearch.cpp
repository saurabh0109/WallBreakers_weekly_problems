class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.empty() || word.empty()) return false;           
                       
        for(int i=0;i<board.size();i++)        
            for(int j=0;j<board[0].size();j++)
                if(board[i][j] == word[0] && doesWordExist(board,i,j,word,1))
                      return true;
            
         return false;                                                      
    }

     bool doesWordExist(vector<vector<char>>& board, int x, int y, string word, int k)   
     {         
         if(k==word.length())
                     return true;
        
        board[x][y]+='a';     
             
        if(x+1 < board.size() && board[x+1][y] == word[k] && doesWordExist(board,x+1,y,word,k+1))
                return true;
        if(x-1 >= 0 && board[x-1][y] == word[k] && doesWordExist(board,x-1,y,word,k+1))
                return true;
        if(y+1 < board[0].size() && board[x][y+1] == word[k] && doesWordExist(board,x,y+1,word,k+1))
                return true;
        if(y-1 >= 0 && board[x][y-1] == word[k] && doesWordExist(board,x,y-1,word,k+1))
                return true;     
                            
         board[x][y]-='a';
         return false;
     }
};