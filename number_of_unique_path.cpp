//Recursion
int f(int i,int j){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        int left = f(i,j-1);
        int up = f(i-1,j);
        return left + up;
    }

//Memoization
int f(int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = f(i,j-1,dp);
        int up = f(i-1,j,dp);
        return dp[i][j]=left + up;
    }

//Tabulation
int f(int a,int b,vector<vector<int>>&dp){
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(i==0&&j==0){ 
                    dp[i][j]=1;
                }
                else{
                    int left=0,up=0;
                    if(i>=1){
                        up = dp[i-1][j];
                    }
                    if(j>=1){
                        left = dp[i][j-1];
                    }
                    dp[i][j]= up + left;
                }
            }
        }
        return dp[a-1][b-1];
    }

//Space Optimization
 int f(int a,int b){
        vector<int> dp(b,0);
        for(int i=0;i<a;i++){
            vector<int>temp(b,0);
            for(int j=0;j<b;j++){
                if(i==0&&j==0){ 
                    temp[j]=1;
                }
                else{
                    int left=0,up=0;
                    if(i>=1){
                        up = dp[j];
                    }
                    if(j>=1){
                        left = temp[j-1];
                    }
                    temp[j]= up + left;
                }
            }
            dp=temp;
        }
        return dp[b-1];
    }
