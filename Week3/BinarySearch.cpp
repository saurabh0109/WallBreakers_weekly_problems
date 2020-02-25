class Solution {
public:
    int search(vector<int>& nums, int target) {
            
            int high = nums.size()-1, low=0 , mid; 
            
            while(low <= high)
            {
                    mid = (low+high)/2;
                    if(nums[mid]==target)
                            return mid;
                    else if(target < nums[mid])
                            high = mid-1;
                    else
                            low = mid+1;
            }
            
            return -1;
    }
};