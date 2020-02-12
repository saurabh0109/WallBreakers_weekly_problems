class UnionFind{
private:
        vector<int> parents;
        int circleCount; 
        
public:
        UnionFind(int n){
                for(int i=0;i<n;i++)
                        parents.push_back(i);
                circleCount=n;
        }
        
        int find(int x){
                if(parents[x] != x) 
                        parents[x]=find(parents[x]);
                return parents[x];
        }
        
        void Union(int x, int y){
                int groupx = find(x);
                int groupy = find(y);
                
                if(groupx != groupy){
                        parents[groupx] = groupy;
                        circleCount--;
                }
        }
        
        int getCircleCount(){
                return circleCount;
        }
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
           int n = M.size();
           if(n <= 1) return n;
            
           UnionFind uf(n);
           
           for(int i=0;i<n;i++){
                   for(int j=i;j<n;j++){
                           if(M[i][j]==1 && i!=j)
                                   uf.Union(i,j);
                   }
           }
            
            
           return uf.getCircleCount();
           
    }
        

};