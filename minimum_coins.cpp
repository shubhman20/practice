//Recursion
int f(vector<int>&coins,int idx,int amount){
        if(idx==0){
            if(amount%coins[idx]==0) return amount/coins[idx];
            return 1e9;
        }
        int notTake = f(coins,idx-1,amount);
        int take=1e9;
        if(coins[idx]<=amount) take = 1+f(coins,idx,amount-coins[idx]);
        return min(notTake,take);
    }


//Memoization
int f(vector<int>&coins,int idx,int amount,vector<vector<int>>&dp){
        if(idx==0){
            if(amount%coins[idx]==0) return amount/coins[idx];
            return 1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notTake = f(coins,idx-1,amount,dp);
        int take=1e9;
        if(coins[idx]<=amount) take = 1+f(coins,idx,amount-coins[idx],dp);
        return dp[idx][amount]=min(notTake,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(coins,n-1,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }

//Tabulation
int f(vector<int>&coins,int n,int amount,vector<vector<int>>&dp){
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else{
                dp[0][i]=1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake = dp[i-1][j];
                int take = 1e9;
                if(coins[i]<=j) take = 1+dp[i][j-coins[i]];
                dp[i][j] = min(take,notTake);
            }
        }
        return dp[n-1][amount];

    }

//Space Optimization
int f(vector<int>&coins,int n,int amount,vector<int>&dp){
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[i]=i/coins[0];
            else{
                dp[i]=1e9;
            }
        }
        for(int i=1;i<n;i++){
            vector<int> temp(amount+1,0);
            for(int j=0;j<=amount;j++){
                int notTake = dp[j];
                int take = 1e9;
                if(coins[i]<=j) take = 1+temp[j-coins[i]];
                temp[j] = min(take,notTake);
            }
            dp=temp;
        }
        return dp[amount];

    }
