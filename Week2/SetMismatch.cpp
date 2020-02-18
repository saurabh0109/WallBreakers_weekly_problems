class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

           if(nums.empty()) return {};
           int x = 0, r = 0;
           for(int i=0; i<nums.size();i++){
                   x^=(abs(nums[i])^(i+1));
                   
                   if(nums[abs(nums[i])-1] < 0) r = abs(nums[i]);
                   nums[abs(nums[i])-1]*=-1;
           }
            
            x^=r;
            return vector<int>{r,x};
    }
};