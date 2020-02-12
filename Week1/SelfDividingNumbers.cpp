class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
            
            vector<int> res;
            for(int num=left;num<=right;num++)
                    if(selfDividing(num)) res.push_back(num);
        
            return res;
    }

    bool selfDividing(int num){
            
            int n=num;
            while(n){
                    int mod = n%10;
                    if(mod == 0 || num%mod!=0) return false; 
                    n = n/10;
            }
            
            return (n==0);
    }    
};