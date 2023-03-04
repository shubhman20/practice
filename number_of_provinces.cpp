class Solution {
public:
    void dfs(int node,vector<vector<int>>&con,vector<int>&vis){
        vis[node]=1;
            for(auto &it:con[node]){
                if(!vis[it]){
                    dfs(it,con,vis);
                }
            }  
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cntProvince = 0;
        vector<vector<int>>adj(isConnected.size()+1);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(adj.size()+1,0);
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                cntProvince++;
            }
        }
        return cntProvince-1;
    }
};
