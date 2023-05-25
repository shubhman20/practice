//Recursion
    int f(vector<int> &arr,int idx,int k,int val){
        if(idx<0){
            if(val==k) return 1;
            else{
                return 0;
            }
        }
        int notTake=f(arr,idx-1,k,val);
        int take = f(arr,idx-1,k,val^arr[idx]);
        return take+notTake;
    }

    int subsetXOR(vector<int> arr, int N, int K) {
        return f(arr,N-1,K,0);
    }

//Memoization
    int f(vector<int> &arr,int idx,int k,int val,vector<vector<int>>&dp){
        if(idx<0){
            if(val==k) return 1;
            else{
                return 0;
            }
        }
        if(dp[idx][val]!=-1) return dp[idx][val];
        int notTake=f(arr,idx-1,k,val,dp);
        int take = f(arr,idx-1,k,val^arr[idx],dp);
        return dp[idx][val]=take+notTake;
    }

    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        int max_ele=INT_MIN;
        for(int i=0;i<N;i++){
            if(arr[i]>max_ele) max_ele = arr[i];
        }
        int m = (1 << (int)(log2(max_ele) + 1)) - 1;
        if (K > m)
            return 0;
        vector<vector<int>> dp(N,vector<int>(m+1,-1));
        return f(arr,N-1,K,0,dp);
    }

//Tabulation
int f(vector<int> &arr,int n,int k,int val,vector<vector<int>>&dp,int m){
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];
            }
        }
        return dp[n][k];
        
    }

//Space Optimization
int f(vector<int> &arr,int n,int k,int val,vector<int>&dp,int m){
        dp[0]=1;
        for(int i=1;i<=n;i++){
            vector<int> temp(m+1,0);
            for(int j=0;j<=m;j++){
                temp[j] = dp[j] + dp[j^arr[i-1]];
            }
            dp=temp;
        }
        return dp[k];
