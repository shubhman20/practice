//Recursion
long long f(int idx,int n,vector<long long>&prices,int fee,int buy){
        if(idx==n) return 0;
        long long transaction=0,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,prices,fee,1) -prices[idx];
            noTransaction = f(idx+1,n,prices,fee,0);
        }
        else{
            transaction = f(idx+1,n,prices,fee,0) + prices[idx]-fee;
            noTransaction = f(idx+1,n,prices,fee,1);
        }
        return max(transaction,noTransaction);
    }

//Memoization
long long f(int idx,int n,vector<long long>&prices,int fee,int buy,vector<vector<long long>>&dp){
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long long transaction=0,noTransaction=0;
        if(buy==0){
            transaction = f(idx+1,n,prices,fee,1,dp) -prices[idx];
            noTransaction = f(idx+1,n,prices,fee,0,dp);
        }
        else{
            transaction = f(idx+1,n,prices,fee,0,dp) + prices[idx]-fee;
            noTransaction = f(idx+1,n,prices,fee,1,dp);
        }
        return dp[idx][buy]=max(transaction,noTransaction);
    }
    
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return f(0,n,prices,fee,0,dp);
    }

//Tabulation
long long f(int n,vector<long long>&prices,int fee,vector<vector<long long>>&dp){
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                long long profit;
                if(buy==0){
                    profit = max(dp[idx+1][1] -prices[idx],dp[idx+1][0]);
                }
                else{
                    profit = max(dp[idx+1][0] + prices[idx]-fee,dp[idx+1][1]);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][0];
    }

//Space Optimization
long long f(int n,vector<long long>&prices,int fee){
        vector<long long> prev(2,0),curr(2,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                long long profit;
                if(buy==0){
                    profit = max(prev[1] -prices[idx],prev[0]);
                }
                else{
                    profit = max(prev[0] + prices[idx]-fee,prev[1]);
                }
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[0];
    }
