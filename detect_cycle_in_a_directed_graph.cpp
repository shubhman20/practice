class Solution {
  public:
  
    bool dfs(int node,vector<int>&vis,vector<int> adj[],vector<int>&DfsVis){
        vis[node]=1;
        DfsVis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,DfsVis)) return true;
            }
            else if(DfsVis[it]) return true;
        }
        DfsVis[node]=0;
        return false;
        
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>DfsVis(V,0);
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(dfs(i,vis,adj,DfsVis)) return true;
        }
        return false;
    }
};
