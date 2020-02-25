class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
            if(A.size() <= 3) return 1;
            
            return findPeak(A,0,A.size()-1);
    }
        
    int findPeak(vector<int>& A, int low, int high){            
                                    
            while(low < high)
            {
                int mid = (low+high)/2;
                if(A[mid] > A[mid-1] && A[mid] > A[mid+1])
                    return mid;
                 else if(A[mid]>A[mid-1] && A[mid] < A[mid+1]) 
                         low = mid;
                 else 
                         high = mid;                    
            }        
            
            return -1;
    }    
};