class TrieNode{
public:
        TrieNode()
        {
            for (int i =0 ; i< 26 ; i++) 
              next[i] = nullptr; 
        }
        
        TrieNode* next[26];
        string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            
            if(words.size() == 0 || board.size() == 0 ) return {};            
            TrieNode* root = BuildTrie(words);
            vector<string> res;
            
            for(int i=0;i<board.size();i++)
                    for(int j=0;j<board[0].size();j++)
                            dfs(board,i,j,root,res);                                
        
            return res;
    }
        
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res)
    {
            char c= board[i][j];
            if(c=='#' || p->next[c-'a'] == nullptr) return;
            p = p->next[c-'a'];
            if(!p->word.empty())
            {
                    res.push_back(p->word);
                    p->word.clear();
            }
            
            board[i][j]='#';
            if(i>0) dfs(board,i-1,j,p,res);
            if(j>0) dfs(board,i,j-1,p,res);
            if(i<board.size()-1) dfs(board,i+1,j,p,res);
            if(j<board[0].size()-1) dfs(board,i,j+1,p,res);
            board[i][j]=c;            
    }
        
        
    TrieNode* BuildTrie(vector<string>& words){
            TrieNode* root = new TrieNode();
            for(auto w : words)
            {
                    TrieNode* p=root; 
                    for(auto c : w)
                    {
                           if(p->next[c-'a'] == nullptr) 
                                p->next[c-'a'] = new TrieNode();
                            p = p->next[c-'a'];
                    }                    
                    p->word = w;
            }            
            return root;
    }
};