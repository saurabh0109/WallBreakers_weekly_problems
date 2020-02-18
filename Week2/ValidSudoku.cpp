class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
            if(board.size() != 9 || board[0].size() != 9) return false;
            
            for(int k=0;k<9;k++){
                if(ValidateRow(board,k) == false) return false;
                if(ValidateColumn(board,k) == false) return false;
            }
            
            for(int i=0;i<9;i+=3)
                 for(int j=0;j<9;j+=3)
                    if(ValidateSubbox(board,i,j) == false) return false;
            
            return true;
    }
        

    bool ValidateRow(vector<vector<char>>& board, int i){
            bool dMap[9] = {false};
            
            for(int j=0;j<9;j++){
                    char c = board[i][j];
                    if(c == '.') continue;
                    if(isSafe(c) && dMap[c-'1'] == false )
                            dMap[c-'1']= true;
                    else
                            return false;
            }
            
            return true;
    }
     
    bool ValidateColumn(vector<vector<char>>& board, int j){
            bool dMap[9] = {false};
            
            for(int i=0;i<9;i++){
                    char c = board[i][j];
                    if(c == '.') continue;
                    if(isSafe(c) && dMap[c-'1'] == false )
                            dMap[c-'1']= true;
                    else
                            return false;
            }
            return true;
    }
    
    bool ValidateSubbox(vector<vector<char>>& board, int x, int y){
            bool dMap[9] = {false};
            
            for(int i=x;i<x+3;i++){
                 for(int j=y;j<y+3;j++){                                         
                            char c = board[i][j];
                            if(c == '.') continue;
                            if(isSafe(c) && dMap[c-'1'] == false )
                                    dMap[c-'1']= true;
                            else
                                    return false;
                 }
            }
            return true;
    }
    
    bool isSafe(char c){
            int d = c - '0';
            return (d>0 && d<=9);
    }
};