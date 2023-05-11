//Recursion
int f(int idx,int val[],int wt[],int W){
        if(idx==0){
            return (W/wt[idx])*val[idx];
        }
        int notTake = f(idx-1,val,wt,W);
        int take = INT_MIN;
        if(wt[idx]<=W) take = val[idx] + f(idx,val,wt,W-wt[idx]);
        return max(notTake,take);
    }

//Memoization
int f(int idx,int val[],int wt[],int W,vector<vector<int>>&dp){
        if(idx==0){
            return (W/wt[idx])*val[idx];
        }
        if(dp[idx][W]!=-1) return dp[idx][W];
        int notTake = f(idx-1,val,wt,W,dp);
        int take = INT_MIN;
        if(wt[idx]<=W) take = val[idx] + f(idx,val,wt,W-wt[idx],dp);
        return dp[idx][W]=max(notTake,take);
    }


    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return f(N-1,val,wt,W,dp);
    }

//Tabulation
int f(int n,int val[],int wt[],int W,vector<vector<int>>&dp){
        for(int i=0;i<=W;i++){
            dp[0][i]= (i/wt[0])*val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int notTake = dp[i-1][j];
                int take=INT_MIN;
                if(wt[i]<=j) take = val[i] + dp[i][j-wt[i]];
                dp[i][j]= max(take,notTake);
            }
        }
        return dp[n-1][W];
    }

//Space Optimisation
int f(int n,int val[],int wt[],int W,vector<int>&dp){
        
        for(int i=0;i<=W;i++){
            dp[i]= (i/wt[0])*val[0];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(W+1,0);
            for(int j=0;j<=W;j++){
                int notTake = dp[j];
                int take=INT_MIN;
                if(wt[i]<=j) take = val[i] + temp[j-wt[i]];
                temp[j]= max(take,notTake);
            }
            dp=temp;
        }
        return dp[W];
    }
