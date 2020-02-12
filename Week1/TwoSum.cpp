class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> hm;            
        for(int i=0;i<nums.size();i++)
        {
                int comp = target-nums[i];
                if(hm.find(comp) != hm.end())
                        return vector<int> { i, hm[comp] };
                else                
                        hm.insert(pair<int,int>(nums[i],i));                
        }
         
        return vector<int> {};
    }
};