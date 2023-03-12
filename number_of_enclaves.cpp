class Solution {
public:
    void dfs(int i,int j,int delrow[],int delcol[],vector<vector<int>> &grid,vector<vector<int>> &vis){
        vis[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();
        for(int k=0;k<4;k++){
            int r = delrow[k]+i;
            int c = delcol[k]+j;
            if(r>=0&&r<n&&c>=0&&c<m&&!vis[r][c]&&grid[r][c]==1){
                dfs(r,c,delrow,delcol,grid,vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[4] = {1,-1,0,0};
        int delcol[4] = {0,0,1,-1};
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,delrow,delcol,grid,vis);
            }

            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,delrow,delcol,grid,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,delrow,delcol,grid,vis);
            }

            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,delrow,delcol,grid,vis);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
