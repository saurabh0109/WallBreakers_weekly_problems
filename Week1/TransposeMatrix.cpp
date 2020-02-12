class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
            if(A.empty()) return A; 
            
            int m= A.size(),n = A[0].size();
            
            //trick lies in the new matrix dimensions
            vector<vector<int>> B(n,vector<int>(m,0));
            
            for(int i=0;i<A.size();i++)
                    for(int j=0;j<A[0].size();j++)
                            B[j][i]= A[i][j];
            
            return B;
    }
};