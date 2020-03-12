class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr){
            vector<vector<int>> graph(numCourses);
            vector<int> inDegrees(numCourses);
            queue<int> q;
            int count = 0;
            
            for(auto p: pr){
                    graph[p[1]].push_back(p[0]);
                    inDegrees[p[0]]++;
            }
          
            for(int i=0;i<inDegrees.size(); i++){
                    if(inDegrees[i] == 0) q.push(i);
            }
            
            vector<int> courseorder; 
            while(!q.empty()){
                    int node = q.front(); q.pop();
                    courseorder.push_back(node);
                    for(int i=0; i< graph[node].size(); i++)
                    {
                            if(--inDegrees[graph[node][i]] == 0) 
                                    q.push(graph[node][i]);
                    }
                    count++;
            }
            
            if(count==numCourses) return courseorder;
            else return {};
    }            
};