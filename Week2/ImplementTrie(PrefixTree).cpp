class TrieNode{
public:
        TrieNode(){
                isLeaf = false;
        }
        
        bool isLeaf;
        map<char,TrieNode*> children;
};

class Trie {
public:
    /** Initialize your data structure here. */
    
    TrieNode* head;
    int wordCount;
        
    Trie() {
        head = new TrieNode();
        wordCount = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tn = head;
        for(auto c: word){
                if(tn->children.find(c) == tn->children.end()){  
                    tn->children[c] = new TrieNode();
                }                
                tn = tn->children[c];
        }           
        tn->isLeaf = true;
        wordCount++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
            if(wordCount == 0) return false;
            TrieNode* tn = head;
            for(auto c: word)
            {
                 if(tn->children.find(c) == tn->children.end())
                         return false;                        
                    tn = tn->children[c];                               
            }           
        return tn->isLeaf;                    
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tn = head;
            for(auto c: prefix)
            {
             if(tn->children.find(c) == tn->children.end())
                     return false;                
                tn = tn->children[c];
             }
           
        return true;            
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */