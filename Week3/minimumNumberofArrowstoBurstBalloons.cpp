class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
            if(points.size() <=1) return points.size();
            
            sort(points.begin(),points.end(),[](vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; });
            
            int c=1, st = points[0][0], end = points[0][1];
            
            for(int i=1;i<points.size();i++){
                    if(end>= points[i][0])
                            end = min(end,points[i][1]);
                    else{
                            c++;
                            end = points[i][1];
                    }                                                
            }
            
            return c;
    }
};