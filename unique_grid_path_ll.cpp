//Recursion
    int f(int i,int j,vector<vector<int>>&grid){
        if(i==0&&j==0&&grid[i][j]!=1) return 1;
        if(i<0||j<0||grid[i][j]==1) return 0;
        int left = f(i,j-1,grid);
        int up = f(i-1,j,grid);
        return left+up;
    }

//Memoization
int mod = 1e9 +7;
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0&&j==0&&grid[i][j]!=1) return 1;
        if(i<0||j<0||grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = f(i,j-1,grid,dp);
        int up = f(i-1,j,grid,dp);
        return dp[i][j]=(left+up)%mod;
    }

//Tabulation
int f(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0&&grid[i][j]!=1){
                    dp[i][j]=1;
                }
                else{
                    int left=0,up=0;
                    if(i>0&&grid[i][j]!=1){
                        up=dp[i-1][j];
                    }
                    if(j>0&&grid[i][j]!=1){
                        left=dp[i][j-1];
                    }
                    dp[i][j]= (left+up)%mod;
                }
            }
        }
        return dp[n-1][m-1];
    }

//Space Optimization
int f(int n,int m,vector<vector<int>>&grid){
        vector<int> dp(m,0);
        for(int i=0;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0&&j==0&&grid[i][j]!=1){
                    temp[j]=1;
                }
                else{
                    int left=0,up=0;
                    if(i>0&&grid[i][j]!=1){
                        up=dp[j];
                    }
                    if(j>0&&grid[i][j]!=1){
                        left=temp[j-1];
                    }
                    temp[j]= (left+up)%mod;
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
 
