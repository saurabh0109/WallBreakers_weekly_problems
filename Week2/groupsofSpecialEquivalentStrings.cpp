class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        
            if(A.size() <= 1) return (int)A.size();
            set<vector<int>> groups;           
            
            for(auto str : A){
                    vector<int> vect(52,0);
                    for(int i=0;i<str.length();i++)
                            vect[str[i] - 'a' + 26*(i%2)]++;
                    groups.insert(vect);
            }
           return groups.size();
    }
                        
};