//Recursion
    int mod = 1e9+7;
    int f(vector<int>&arr,int idx,int sum){
        if(idx==0){
            if(sum==0&&arr[idx]==0) return 2;
            if(sum==0) return 1;
            return arr[idx]==sum;
        }
        int notTake=f(arr,idx-1,sum);
        int take=0;
        if(arr[idx]<=sum) take=f(arr,idx-1,sum-arr[idx]);
        return (take+notTake)%mod;
    }
    
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum=0;
        for(int i=0;i<n;i++){
            totSum+=arr[i];
        }
        if((totSum-d)<0||(totSum-d)%2!=0) return 0;
        return f(arr,n-1,(totSum-d)/2);
    }

//Memoization
int mod = 1e9+7;
    int f(vector<int>&arr,int idx,int sum,vector<vector<int>>&dp){
        if(idx==0){
            if(sum==0&&arr[idx]==0) return 2;
            if(sum==0) return 1;
            return arr[idx]==sum;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int notTake=f(arr,idx-1,sum,dp);
        int take=0;
        if(arr[idx]<=sum) take=f(arr,idx-1,sum-arr[idx],dp);
        return dp[idx][sum]=(take+notTake)%mod;
    }

//Tabulation
int mod = 1e9+7;
    int f(vector<int>&arr,int n,int sum,vector<vector<int>>&dp){
        for(int i=0;i<n;i++){
            dp[i][0]=1;
            if(arr[i]==0) dp[i][0]++;
        }
        if(arr[0]<=sum){
            dp[0][arr[0]]=1;
            if(arr[0]==0) dp[0][arr[0]]++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int notTake = dp[i-1][j];
                int take=0;
                if(arr[i]<=j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = (take+notTake)%mod;
            }
        }
        return dp[n-1][sum];
    }

//Space Optimization
int f(vector<int>&arr,int n,int sum,vector<int>&dp){
        dp[0]=1;
        if(arr[0]<=sum){
            dp[arr[0]]=1;
            if(arr[0]==0) dp[arr[0]]++;
        }
        for(int i=1;i<n;i++){
            vector<int> temp(sum+1,0);
            temp[0]=1;
            for(int j=0;j<=sum;j++){
                int notTake = dp[j];
                int take=0;
                if(arr[i]<=j){
                    take = dp[j-arr[i]];
                }
                temp[j] = (take+notTake)%mod;
            }
            dp=temp;
        }
        return dp[sum];
    }
