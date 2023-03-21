// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> dist(N,INT_MAX);
        queue<int> q;
        q.push(0);dist[0]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for( auto &it: adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                    q.push(it.first);
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
