//Recursion
long long int f(int coins[],int idx,int sum){
        if(idx==0){
            if(sum%coins[idx]==0) return 1;
            return 0;
        }
        long long int notTake= f(coins,idx-1,sum);
        long long int take=0;
        if(coins[idx]<=sum) take = f(coins,idx,sum-coins[idx]);
        return take+notTake;
    }

//Memoization
long long int f(int coins[],int idx,int sum,vector<vector<long long int>>&dp){
        if(idx==0){
            if(sum%coins[idx]==0) return 1;
            return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        long long int notTake= f(coins,idx-1,sum,dp);
        long long int take=0;
        if(coins[idx]<=sum) take = f(coins,idx,sum-coins[idx],dp);
        return dp[idx][sum]=take+notTake;
    }

  
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return f(coins,N-1,sum,dp);
    }

//Tabulation
 long long int f(int coins[],int n,int sum,vector<vector<long long int>>&dp){
        for(int i=0;i<=sum;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                long long int notTake = dp[i-1][j];
                long long int take=0;
                if(coins[i]<=j) take=dp[i][j-coins[i]];
                dp[i][j]=notTake+take;
            }
        }
        return dp[n-1][sum];
        
    }

//Space Optimization
 long long int f(int coins[],int n,int sum,vector<long long int>&dp){
        for(int i=0;i<=sum;i++){
            if(i%coins[0]==0) dp[i]=1;
        }
        
        for(int i=1;i<n;i++){
            vector<long long int> temp(sum+1,0);
            for(int j=0;j<=sum;j++){
                long long int notTake = dp[j];
                long long int take=0;
                if(coins[i]<=j) take=temp[j-coins[i]];
                temp[j]=notTake+take;
            }
            dp=temp;
        }
        return dp[sum];
        
    }
