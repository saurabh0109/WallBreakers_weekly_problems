class LRUCache {
public:
        
    typedef pair<int,int> Pair;    
    list<Pair> dq;
    map<int, list<Pair>::iterator> hash;            
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) 
    {
        int value = -1;
        if(hash.find(key) != hash.end())
        {                
                value = hash[key]->second;
                
                dq.erase(hash[key]);
                dq.push_front({key,value});
                hash[key] = dq.begin();
        }
        
        return value;
    }
    
    void put(int key, int value) {
        
            if(hash.find(key) == hash.end())
            {
                    if(dq.size() == cap){                            
                            hash.erase(hash.find(dq.back().first));
                            dq.pop_back();                                                                     
                    }
                    
                    dq.push_front({key,value});
                    hash[key]=dq.begin();                    
            }
           else
           {                   
                   dq.erase(hash[key]);
                   dq.push_front({key,value});
                   hash[key] = dq.begin();
           }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */