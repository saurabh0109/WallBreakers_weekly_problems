class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
            int min = INT_MAX, profit = 0 ;
                        
            for(auto p : prices)
            {
                    if( p <= min)
                            min = p;
                    
                    profit = max(profit, p - min);
            }
            
            return profit;
    }
};