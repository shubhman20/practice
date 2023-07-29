//User function Template for C++

class Solution{   
public:
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    

    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>> adj(N,vector<int>(M,0));
        adj[x-1][y-1]=1;
        int cnt=0;
        queue<pair<int,int>> q;
        q.push({x-1,y-1});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int xi = q.front().first;
                int yi = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int xt = xi + X[j];
                    int yt = yi + Y[j];
                    if(xt>=0 && xt<N && yt>=0 && yt<M && adj[xt][yt]==0){
                        q.push({xt,yt});
                        adj[xt][yt]=1;
                    }
                }
            }
            cnt++;
            
        }
        return cnt-1;
    }
};
