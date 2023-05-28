//Recursion
int f(int idx,int n,int k,int A[],int buy){
        if(k==0||idx==n) return 0;
        int transaction=0,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,k,A,1) - A[idx];
            noTransaction = f(idx+1,n,k,A,0);
        }
        else{
            transaction = f(idx+1,n,k-1,A,0) + A[idx];
            noTransaction = f(idx+1,n,k,A,1);
        }
        return max(transaction,noTransaction);
    }

//Memoziation
 int f(int idx,int n,int k,int A[],int buy,vector<vector<vector<int>>>&dp){
        if(k==0||idx==n) return 0;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        int transaction=0,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,k,A,1,dp) - A[idx];
            noTransaction = f(idx+1,n,k,A,0,dp);
        }
        else{
            transaction = f(idx+1,n,k-1,A,0,dp) + A[idx];
            noTransaction = f(idx+1,n,k,A,1,dp);
        }
        return dp[idx][buy][k]= max(transaction,noTransaction);
    }
  
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        
        return f(0,N,K,A,0,dp);
    }

//Tabulation
int f(int n,int K,int A[],vector<vector<vector<int>>>&dp){
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=K;k++){
                    int profit=0;
                    if(j==0){
                        profit = max(dp[i+1][1][k]-A[i],dp[i+1][0][k]);
                    }
                    else{
                        profit = max(dp[i+1][0][k-1]+A[i],dp[i+1][1][k]);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }
        return dp[0][0][K];
    }

//Space Optimization
int f(int n,int K,int A[]){
        vector<vector<int>> dp(2,vector<int>(K+1,0)),curr(2,vector<int>(K+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<=K;k++){
                    int profit=0;
                    if(j==0){
                        profit = max(dp[1][k]-A[i],dp[0][k]);
                    }
                    else{
                        profit = max(dp[0][k-1]+A[i],dp[1][k]);
                    }
                    curr[j][k] = profit;
                }
            }
            dp=curr;
        }
        return dp[0][K];
    }
