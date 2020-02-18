class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
            if(candies.size() == 0) return 0;
            
            unordered_set<int> s;
            for(auto c : candies)
                    s.insert(c);
            
            return min(s.size(),candies.size()/2);
    }
};