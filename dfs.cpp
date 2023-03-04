class Solution {
  public:
  
  void dfs(int node,vector<int> &vis,vector<int>adj[],vector<int>&storeDfs){
        vis[node]=1;
        storeDfs.push_back(node);
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,storeDfs);
            }
        }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> Dfs;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,adj,Dfs);
            }
        }
        return Dfs;
    }
};
