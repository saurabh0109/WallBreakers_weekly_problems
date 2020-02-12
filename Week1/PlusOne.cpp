class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
            int i = digits.size() - 1;
            bool carryover = false;
                        
            while(i>=0)
            {
                    if(digits[i]+1==10){
                            digits[i]=0;
                            carryover=true;
                    }
                    else {
                            digits[i]++;
                            return digits;
                    }
                    i--;
            }
            
            if(carryover) digits.insert(digits.begin(),1);
            
            return digits;
    }
};