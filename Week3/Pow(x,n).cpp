class Solution {
public:
    double myPow(double x, int n) {
        
            if(n==0) return 1;
                  
            double k = myPow(x,n/2); 
            
            if(n%2==0) return k*k;
            else{
                if(n>0)                    
                     return k*k*x;
                 else
                     return (k*k)/x;
            }            
    }
};