class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size(); 
        if(n == 0) return 0;               
        if(n == 1) return nums[0];  
        if(n == 2) return max(nums[0],nums[1]);    
            
        vector<int> dp (n,0); 
            
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);       
        int ans1 = robUtil(nums,2,n-1,dp);  // house 0 robbed
            
        dp.clear();
        dp[0] = 0;
        dp[1] = nums[1];    
        int ans2 = robUtil(nums,2,n,dp);  // house 0 not robbed      
        
        return max(ans1,ans2);
    }
        
    int robUtil(vector<int>& nums,int i, int end, vector<int>& mem)
    {
        for(int k=i;k<end;k++)
                mem[k] = max( mem[k-2]+nums[k], mem[k-1]);           
        return mem[end-1];    
    }
};
        
