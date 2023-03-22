class Solution {
public:
    int x[8] = {1,0,-1,0,-1,-1,1,1};
    int y[8] = {0,1,0,-1,-1,1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        else if(n==1&& grid[0][0]==0) return 1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        vis[0][0]=1;
        while(!q.empty()){
            int xi = q.front().first.first;
            int yi = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int xidx = xi + x[i];
                int yidx = yi + y[i];
                if(xidx==n-1 && yidx==n-1){
                    ans = min(ans,dist+1);
                } 
                else if(xidx>=0 && xidx<n &&yidx>=0 && yidx<n && vis[xidx][yidx]!=1&&grid[xidx][yidx]==0){
                    q.push({{xidx,yidx},dist+1});
                    vis[xidx][yidx]=1;
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
