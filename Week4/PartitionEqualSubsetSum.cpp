class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
            
        int sum=0;
        for(auto i : nums) sum+=i;
        
        if(sum%2!=0) return false;             
        sum/=2;
        vector<vector<int>> memo(nums.size(),vector<int>(sum+1,-1));
            
        return isSubsetSum(nums, (int)nums.size(), sum, memo);            
    }
        
    bool isSubsetSum(vector<int>& nums,int n, int sum, vector<vector<int>>& memo)
    {
            if(sum == 0) return true;
            else if(n==0) return false;
            
            if(memo[n-1][sum] != -1) return memo[n-1][sum] ? true : false;                        
            bool ret;
            if(nums[n-1] > sum) 
                    ret = isSubsetSum(nums,n-1,sum,memo);
            else 
                    ret = isSubsetSum(nums,n-1,sum-nums[n-1],memo) 
                                || isSubsetSum(nums,n-1,sum,memo);
            memo[n-1][sum] = (ret ? 1 : 0);     
            return ret;
    }    
};