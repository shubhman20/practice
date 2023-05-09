//Recursion
int f(int idx,int W,int wt[],int val[]){
        if(idx==0){
            if(wt[idx]<=W){
                return val[idx];
            }
            return 0;
        }
        int notTake = f(idx-1,W,wt,val,dp);
        int take=INT_MIN;
        if(wt[idx]<=W){
            take = val[idx] + f(idx-1,W-wt[idx],wt,val,dp);
        }
        return max(take,notTake);
    }


//Memoization
int f(int idx,int W,int wt[],int val[],vector<vector<int>>&dp){
        if(idx==0){
            if(wt[idx]<=W){
                return val[idx];
            }
            return 0;
        }
        if(dp[idx][W]!=-1) return dp[idx][W];
        int notTake = f(idx-1,W,wt,val,dp);
        int take=INT_MIN;
        if(wt[idx]<=W){
            take = val[idx] + f(idx-1,W-wt[idx],wt,val,dp);
        }
        return dp[idx][W]=max(take,notTake);
    }

//Tabulation
int f(int n,int W,int wt[],int val[],vector<vector<int>>&dp){
        for(int i=wt[0];i<=W;i++){
            dp[0][i]= val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int notTake=dp[i-1][j];
                int take=INT_MIN;
                if(wt[i]<=j) take = val[i]+dp[i-1][j-wt[i]];
                dp[i][j]= max(take,notTake);
            }
        }
        return dp[n-1][W];
    }

//Space Optimization
  int f(int n,int W,int wt[],int val[],vector<int>&dp){
        for(int i=wt[0];i<=W;i++){
            dp[i]= val[0];
        }
        for(int i=1;i<n;i++){
            vector<int>temp(W+1,0);
            for(int j=0;j<=W;j++){
                int notTake=dp[j];
                int take=INT_MIN;
                if(wt[i]<=j) take = val[i]+dp[j-wt[i]];
                temp[j]= max(take,notTake);
            }
            dp=temp;
        }
        return dp[W];
    }
