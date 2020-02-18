class Solution {
public:
    string frequencySort(string s) {
        
            if (s.empty()) return s;
            
            map<char,int> m;
            for(auto c : s) 
                    m[c]++;
            
            multimap<int,char, greater<int>> im;
            for( auto c: m)
                    im.insert(make_pair(c.second,c.first));            
            
            string ns;
            for(auto i: im)
                    ns.append(i.first,i.second);
            
            //reverse(ns.begin(),ns.end());
            return ns;
    }
};