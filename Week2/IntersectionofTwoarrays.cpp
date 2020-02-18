class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            
            if(nums1.size() <=0 || nums2.size() <=0) return {};
            set<int> s; 
            set<int> res;
            
            if(nums1.size() < nums2.size()){
                    for(auto i: nums1) s.insert(i);
                    
                    for(auto i : nums2)
                            if(s.find(i) != s.end()) res.insert(i);             
            }
            else{
                    for(auto i: nums2) s.insert(i);
                    
                    for(auto i : nums1)
                            if(s.find(i) != s.end()) res.insert(i);             
            }
            
            return vector<int>(res.begin(),res.end());
        
    }
};