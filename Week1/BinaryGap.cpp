class Solution {
public:
    int binaryGap(int N) {
        
            if(N==0) return N;
            int maxDist = 0, last1Idx = -1, curIdx = 1;
            
            while(N)
            {
                    if(N&1){                    
                         if(last1Idx>0) 
                             maxDist = max(maxDist,curIdx-last1Idx);
                         last1Idx = curIdx;
                    }
                    
                    curIdx++;
                    N>>=1;
            }
            
            return maxDist;
    }
};