
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            
            vector<vector<int>> vv;
            if(intervals.empty()) return vv;
            sort(intervals.begin(),intervals.end(),[](vector<int> v1,vector<int> v2){  return (v1[0] < v2[0]); });
        
            
            int start = intervals[0][0],end=intervals[0][1]; 
            for(int i=1;i<intervals.size();i++)
            {
                    if(intervals[i][0] > end){                    
                            vv.push_back(vector<int> {start,end});
                            start = intervals[i][0];
                            end = intervals[i][1];
                    }
                    else if(intervals[i][1] > end)
                    {                                    
                           end  = intervals[i][1];                                            
                    }
                    
            }
            vv.push_back(vector<int> {start,end});
        
            return vv;
    }
};