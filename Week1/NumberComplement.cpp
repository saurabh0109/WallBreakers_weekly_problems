class Solution {
public:
    int findComplement(int num) {
            
            bool atStart = false;
            
            for(int i=31;i>=0;i--)
            {
                    int p = pow(2,i);
                    if(num&p) atStart = true;
                    if(atStart) num ^= p;
            }
            
            return num;
        
    }
};