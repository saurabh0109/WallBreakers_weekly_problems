class Solution {
public:
    bool isHappy(int n) {        
            int cur = n;            
            
            unordered_set<int> s;
            s.insert(cur);
            cur = returnSumofSquares(cur);
            while(cur != 1){
                    cur = returnSumofSquares(cur);
                    if(s.find(cur) != s.end()) return false;
                    s.insert(cur);
            }            
            return (cur==1);            
    }
        
    int returnSumofSquares(int n){
            int sum=0;
            while(n>0){
                    int mod = n%10;
                    sum += (mod*mod);
                    n = n/10;
            }            
            return sum;
    }
};