class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
                        
            if(nums1.empty() || nums2.empty()) return {};
            
            unordered_map<int,int> om;
            stack<int> s;
            
            for(auto i : nums2){
                    while(!s.empty() && s.top() < i){
                            om[s.top()]=i;
                            s.pop();
                    }                    
                    s.push(i);
            }
            
            vector<int> res;
            for(auto k : nums1){
                    if(om.find(k) != om.end())
                        res.push_back(om[k]);
                    else
                        res.push_back(-1);   
            }
            
            return res;        
    }
};