/*<----DFS--->
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int par ,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto &it: adj[node]){
            if(!vis[it]){
                if(dfs(it,node,vis,adj)) return true;
            }
            else{
                if(it!=par) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};
*/
/*<---BFS--->*/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int par ,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto &it: adj[node]){
            if(!vis[it]){
                if(dfs(it,node,vis,adj)) return true;
            }
            else{
                if(it!=par) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vis[i]=1;
                queue<pair<int,int>>q;
                q.push({i,-1});
                while(!q.empty()){
                    int node = q.front().first;
                    int par = q.front().second;
                    q.pop();
                    for(auto &it: adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push({it,node});
                        }
                        else{
                            if(it!=par) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
