class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    bitset<1000001> s;    
    MyHashSet() {
        
    }
    
    void add(int key) {
        s.set(key);
    }
    
    void remove(int key) {
        s.set(key,0);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return s.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */