class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
            
            sort(nums.begin(),nums.end());
            
            int i=0,sum=0,j=nums.size();
            
            while(i<j)
            {
                 sum+=nums[i];
                 i+=2; 
            }
        
            return sum;
    }
};