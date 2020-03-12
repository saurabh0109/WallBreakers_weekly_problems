class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
      
      unordered_map<int,int> hash;
      for( auto i : nums) 
        hash[i]++;     
           
      typedef pair<int,int> Pair;
      auto compare = [](Pair& a, Pair& b) { return a.second < b.second; };

      priority_queue<Pair, vector<Pair>, decltype(compare)> pq(compare);
      
      for(auto m : hash)
        pq.push(Pair(m.first,m.second));
      
      vector<int> res;
      for(int i=0;i<k;i++){
         res.push_back(pq.top().first);
         pq.pop();
      }
      
      return res;                                   
    }
    
};