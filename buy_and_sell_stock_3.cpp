//Recursion
int f(int idx,int n,vector<int>&price,int cnt,int buy){
    if(cnt==2) return 0;
    if(idx==n){
        return 0;
    }
    int transaction=0,noTransaction=0;
    if(buy==0){
        transaction = f(idx+1,n,price,cnt,1) - price[idx];
        noTransaction = f(idx+1,n,price,cnt,0);
    }
    else{
        transaction = f(idx+1,n,price,cnt+1,0) + price[idx];
        noTransaction = f(idx+1,n,price,cnt,1);
    }
    return max(transaction,noTransaction);
}

//Memoization
int f(int idx,int n,vector<int>&price,int cnt,int buy,vector<vector<vector<int>>>&dp){
    if(cnt==2) return 0;
    if(idx==n){
        return 0;
    }
    if(dp[idx][buy][cnt]!=-1) return dp[idx][buy][cnt];
    int transaction=0,noTransaction=0;
    if(buy==0){
        transaction = f(idx+1,n,price,cnt,1,dp) - price[idx];
        noTransaction = f(idx+1,n,price,cnt,0,dp);
    }
    else{
        transaction = f(idx+1,n,price,cnt+1,0,dp) + price[idx];
        noTransaction = f(idx+1,n,price,cnt,1,dp);
    }
    return dp[idx][buy][cnt]=max(transaction,noTransaction);
}


int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,n,price,0,0,dp);
}

//Tabulation
int f(int n,vector<int>&price,vector<vector<vector<int>>>&dp){    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            int profit=0;
            for(int k=0;k<2;k++){
                if(j==0){
                    profit = max(dp[i+1][1][k]-price[i],dp[i+1][0][k]);
                }
                else{
                    profit = max(dp[i+1][0][k+1]+price[i],dp[i+1][1][k]);
                }
                dp[i][j][k]=profit;
            }
        }
    }
    return dp[0][0][0];
    
}

//Space Optimization
int f(int n,vector<int>&price){
vector<vector<int>> dp(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            int profit=0;
            for(int k=0;k<2;k++){
                if(j==0){
                    profit = max(dp[1][k]-price[i],dp[0][k]);
                }
                else{
                    profit = max(dp[0][k+1]+price[i],dp[1][k]);
                }
                curr[j][k]=profit;
            }
        }
        dp=curr;
    }
    return dp[0][0];
    
}
