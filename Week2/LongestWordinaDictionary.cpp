class TrieNode{
public:
        TrieNode()
        {
            for (int i =0 ; i< 26 ; i++) 
              next[i] = nullptr; 
            isLeaf = false;
        }
        
        TrieNode* next[26];
        bool isLeaf;
};

class Solution {
public:
    string longestWord(vector<string>& words) 
    {
        
        if(words.empty()) return "";
        TrieNode* root = BuildTrie(words);
        
         int ml=0;
         string lword;
         
         for(auto w: words)
         {
                 if(w.length() < ml) continue;
                 TrieNode* p=root;
                 
                 if(w.length() == 1){
                         lword = lword.empty() ? w : lword;
                         continue;
                 }
                 for(int i=0;i<w.length()-1;i++)
                 {
                         if(p->next[w[i]-'a'] == nullptr) break;
                         if(p->next[w[i]-'a']->isLeaf == false) break;
                         
                         if(i == w.length()-2)
                         {
                                 if(ml == w.length())
                                         lword = w.compare(lword) < 0 ? w : lword; 
                                 else{
                                         ml = w.length();
                                         lword = w;
                                 }
                         }
                         p = p->next[w[i]-'a'];
                 }                                                  
         }
        return lword;             
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
                    p->isLeaf = true;
            }            
            return root;
    }
};

//lexicographical_compare