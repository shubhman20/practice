//Recursion
long long f(int idx,int n,vector<long long>&price,int buy){
        if(idx>=n) return 0;
        int transaction=0,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,price,1) - price[idx];
            noTransaction = f(idx+1,n,price,0);
        }
        else{
            transaction = f(idx+2,n,price,0) + price[idx];
            noTransaction = f(idx+1,n,price,1);
        }
        return max(transaction,noTransaction);
    }

//Memoization
long long f(int idx,int n,vector<long long>&price,int buy,vector<vector<long long>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int transaction=0,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,price,1,dp) - price[idx];
            noTransaction = f(idx+1,n,price,0,dp);
        }
        else{
            transaction = f(idx+2,n,price,0,dp) + price[idx];
            noTransaction = f(idx+1,n,price,1,dp);
        }
        return dp[idx][buy]=max(transaction,noTransaction);
    }
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        
        return f(0,n,prices,0,dp);
    }

//Tabulation
 long long f(int n,vector<long long>&price,vector<vector<long long>>&dp){
        for(int i=n-1;i>=0;i--){
            long long profit=0;
            for(int j=0;j<2;j++){
                if(j==0){
                    profit = max(dp[i+1][1]-price[i],dp[i+1][0]);
                }
                else{
                    profit = max(dp[i+2][0]+price[i],dp[i+1][1]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][0];
    }

//Space Optimization
 long long f(int n,vector<long long>&price){
        vector<long long> prev(2,0), curr(2,0);
        long long prev2=0;
        for(int i=n-1;i>=0;i--){
            long long profit=0;
            for(int j=0;j<2;j++){
                if(j==0){
                    profit = max(prev[1]-price[i],prev[0]);
                }
                else{
                    profit = max(prev2+price[i],prev[1]);
                }
                curr[j] = profit;
            }
            prev2 = prev[0];
            prev=curr;
        }
        return prev[0];
    }
