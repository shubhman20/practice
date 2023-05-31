//Recursion   TC-----> O(Exp.) , SC-----> O(n^2) + O(n)
int f(int i,int j,int arr[]){
        if(i==j) return 0;
        int mini=1e9;
        for(int k=i;k<j;k++){
            int val = arr[i-1]*arr[k]*arr[j] + f(i,k,arr) + f(k+1,j,arr);
            if(val<mini) mini=val;
        }
        return mini;
    }

//Memoization TC-----> O(n^3) , SC------> O(n^2) + O(n)
int f(int i,int j,int arr[],vector<vector<int>> &dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++){
            int val = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
            if(val<mini) mini=val;
        }
        return dp[i][j]=mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return f(1,N-1,arr,dp);
    }

//Tabulation  TC-----> O(n^3) , SC------> O(n^2)
 int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,0));
        
        for(int i=N-1;i>=0;i--){
            for(int j=i+1;j<N;j++){
                int mini=1e9;
                for(int k=i;k<j;k++){
                    int val = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    if(val<mini) mini=val;
                }
                dp[i][j]=mini;
            }
        }
        
        return dp[1][N-1];
    }
