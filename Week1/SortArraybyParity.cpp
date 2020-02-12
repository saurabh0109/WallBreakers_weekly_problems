class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
            
         int i = 0, j = A.size() - 1;
         while (i < j) 
         {
            if (A[i] % 2 > A[j] % 2)             
                swap(A[i],A[j]);            

            while (i<j && A[i] % 2 == 0) i++;
            while (i<j && A[j] % 2 == 1) j--;
        }

        return A;        
    }
};