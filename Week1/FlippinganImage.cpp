class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        vector<vector<int>> F;
        
        for (auto itr = A.begin() ; itr != A.end();itr++)
        {
            vector<int> row (*itr);
            reverse(row.begin(),row.end());
            
            for(auto it=row.begin();it!=row.end();it++)
            {
                *it ^= 1;
            }
            
            F.push_back(row);
        }
        
        return F;
    }
};