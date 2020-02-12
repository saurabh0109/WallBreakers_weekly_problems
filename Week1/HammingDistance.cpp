class Solution {
public:
    int hammingDistance(int x, int y) {
        
            int Xor = x^y ;
            int count = 0;
            
            while(Xor){
                    if(Xor&1) count++;
                    Xor = Xor >> 1;
            }
            
            return count;
    }
};