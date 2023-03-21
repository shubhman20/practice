class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int>dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,S});
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int Dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for( auto &it : adj[node]){
                int adjNode = it[0];
                int adjDist = it[1];
                if(Dist + adjDist < dist[adjNode]){
                    dist[adjNode] = Dist + adjDist;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
        
    }
};
