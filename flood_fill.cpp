class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int t = image[sr][sc];
        if(color==t) return image;
        int k = image[0].size();
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>>vis(image.size(),(vector<int>(image[0].size(),0)));
        vis[sr][sc]=1;
        image[sr][sc]=color;
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r = a + x[i];
                int c = b + y[i];
                if(r>=0&&r<image.size()&&c>=0&&c<k&&vis[r][c]==0&&image[r][c]==t){
                    image[r][c]=color;
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
        return image;
    }
};
