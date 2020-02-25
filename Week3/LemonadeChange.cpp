class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
            int C1 = 0, C2 = 0, C3 = 0;
            
            for(auto b : bills)
            {
                    switch(b)
                    {
                            case 5: C1++;break;
                            case 10: C1--;C2++;break;
                            case 20: 
                                    if(C2 >= 1){
                                            C2--;
                                            C1--;
                                    }
                                    else
                                            C1-=3;
                                    C3++;
                                    break;
                    }
                    
                    if(C1 < 0 || C2 < 0 || C3 < 0)
                            return false;
            }
            
            return true;
            
            
        
    }
};