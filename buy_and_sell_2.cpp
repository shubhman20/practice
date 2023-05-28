//Recursion
long long f(int idx,int n,vector<long long>&prices,int buy){
        if(idx==n) return 0;
        int transaction =0 ,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,prices,1) - prices[idx];
            noTransaction = f(idx+1,n,prices,0);
        }
        else{
            transaction = f(idx+1,n,prices,0) + prices[idx];
            noTransaction = f(idx+1,n,prices,1);
        }
        return max(transaction,noTransaction);
    }
//Memoization
long long f(int idx,int n,vector<long long>&prices,int buy,vector<vector<long long>> &dp){
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int transaction =0 ,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,prices,1,dp) - prices[idx];
            noTransaction = f(idx+1,n,prices,0,dp);
        }
        else{
            transaction = f(idx+1,n,prices,0,dp) + prices[idx];
            noTransaction = f(idx+1,n,prices,1,dp);
        }
        return dp[idx][buy]=max(transaction,noTransaction);
    }
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return f(0,n,prices,0,dp);
    }

//Tabulation
long long f(int idx,int n,vector<long long>&prices,int buy,vector<vector<long long>> &dp){
        dp[n][1]=0;dp[n][0]=0;
        for(int i=n-1;i>=0;i--){
            long long profit = 0;
            for(int j=0;j<2;j++){
                if(j==0){
                    profit = max(dp[i+1][1]-prices[i],dp[i+1][0]);
                }
                else{
                    profit = max(dp[i+1][0]+prices[i],dp[i+1][1]);
                }
                dp[i][j]=profit;
            }
            
        }
        return dp[0][0];
    }

//Space Optimization
long long f(int n,vector<long long>&prices){
        vector<long long> dp(2),curr(2);
        dp[0]=0;dp[1]=1;
        for(int i=n-1;i>=0;i--){
            long long profit = 0;
            for(int j=0;j<2;j++){
                if(j==0){
                    profit = max(dp[1]-prices[i],dp[0]);
                }
                else{
                    profit = max(dp[0]+prices[i],dp[1]);
                }
                curr[j]=profit;
            }
            dp=curr;
            
        }
        return dp[0];
    }
