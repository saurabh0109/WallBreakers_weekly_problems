class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {        
      if(graph.empty()) return false; 
      int n = graph.size();
      vector<int> color(n,-1);
     
      for(int i=0;i<n;i++){
        if(color[i] == -1 && isBipartitleUtil(graph,color,i) == false)
          return false;
      }      
      return true;
    }
  
    bool isBipartitleUtil(vector<vector<int>>& graph, vector<int>& color, int src){             
        queue<int> q; 
        q.push(src);
        color[src]=1;

        while(!q.empty())
        {        
          int node = q.front();
          q.pop();

          for(auto adj : graph[node])
          {
            if(adj == node) return false;
            if(color[adj] == -1)
            {
              color[adj] = 1 - color[node];
              q.push(adj);
            }
            else if(color[adj] == color[node])
              return false;
          }        
        }
        return true;     
    }
};