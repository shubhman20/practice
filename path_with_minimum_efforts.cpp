class Solution {
public:
    int x[4] = {0,0,1,-1};
    int y[4] = {-1,1,0,0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.size()==1 && heights[0].size()==1) return 0;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
        pq.push({{0,0},0});
        dist[0][0]=0;
        while(!pq.empty()){
            int xi = pq.top().first.first;
            int yi = pq.top().first.second;
            int val = pq.top().second;
            if(xi==n-1&&yi==m-1) return val;
            pq.pop();
            for(int i=0;i<4;i++){
                int xVal = xi + x[i];
                int yVal = yi + y[i];
                if(xVal>=0 && xVal<n &&yVal>=0&&yVal<m){
                    int newVal = max(val,abs(heights[xi][yi]-heights[xVal][yVal]));
                    if(newVal<dist[xVal][yVal]){
                        dist[xVal][yVal]=newVal;
                        pq.push({{xVal,yVal},newVal});
                    }
                }
            }
        }
        return 0;
    }
};
