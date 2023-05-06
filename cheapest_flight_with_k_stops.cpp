class Solution {
  public:
    int ans=INT_MAX;
    void dfs(int src,int dst,vector<vector<pair<int,int>>>&adj,int k,int cnt){
        // cout<<"src "<<src<<endl;
        if(k<0 && src!=dst){
            return;
        }
        if(src==dst){
            ans = min(ans,cnt);
        }
        // int val = adj[src].size();
        for(auto &it : adj[src]){
                dfs(it.first,dst,adj,k-1,cnt+it.second);
        }
    }
    
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        // int cnt=0;
        dfs(src,dst,adj,K,0);
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};
