class Solution {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dis[a][b]=step;
            for(int i=0;i<4;i++){
                int r = a+x[i];
                int c = b+y[i];
                if(r>=0&&r<n&&c>=0&&c<m&&vis[r][c]==0){
                    q.push({{r,c},step+1});
                    vis[r][c]=1;
                }
            }
        }
        return dis;
        
    }
};
