class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.empty()) return 0;
        int n = nums.size();    
            
        if(nums.size() == 1) return nums[0];                    
        map<int,int> mem;
            
        int ans1 = robUtil(nums,0,n-2, mem);
        mem.clear();
        int ans2 = robUtil(nums,1,n-1, mem);        
        
        return max(ans1,ans2);
    }
        
    int robUtil(vector<int>& nums,int i, int end, map<int,int>& mem)
    {
        if(i > end) return 0;
                          
        if(mem.find(i) != mem.end()) 
                return mem[i];   
                        
        if(i == end) mem[i] = nums[i];
        else if(i < end)
            mem[i] = max(nums[i] + robUtil(nums,i+2,end,mem), robUtil(nums,i+1,end,mem));        
        
        return mem[i];    
    }
        
};
