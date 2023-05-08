//Recursion
int f(int sum,int arr[],int idx){
	    if(idx==0){
	        if(sum==0&&arr[idx]==0) return 2;
	        if(sum==0) return 1;
	        return sum==arr[0];
	    }
	    int take=0,notTake=0;
	    if(sum>=arr[idx]){
	        take=f(sum-arr[idx],arr,idx-1);
	    }
	    notTake=f(sum,arr,idx-1);
	    return (take+notTake)%mod;
	}

//Memoization
 int mod = 1e9+7;
	int f(int sum,int arr[],int idx,vector<vector<int>>&dp){
	    
	   // if(sum==0) return 1;
	    if(idx==0){
	        if(sum==0&&arr[idx]==0) return 2;
	        if(sum==0) return 1;
	        return sum==arr[0];
	    }
	    if(dp[idx][sum]!=-1) 
	        return dp[idx][sum];
	    int take=0,notTake=0;
	    if(sum>=arr[idx]){
	        take=f(sum-arr[idx],arr,idx-1,dp);
	    }
	    notTake=f(sum,arr,idx-1,dp);
	    return dp[idx][sum]=(take+notTake)%mod;
	}

//Tabulation
int f(int sum,int arr[],int n,vector<vector<int>>&dp){
	   // if(n==0){
	   //     if(sum==0&&arr[idx]==0) return 2;
	   //     if(sum==0) return 1;
	   //     return sum==arr[0];
	   // }
	    for(int i=0;i<n;i++){
	        dp[i][0]=1;
	        if(arr[i]==0){
	            dp[i][0]++;
	        }
	    }
	    if(arr[0]<=sum){ 
	        dp[0][arr[0]]=1;
	        if(arr[0]==0){
	            dp[0][arr[0]]++;
	        }
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j<=sum;j++){
	            int take=0;
	            int notTake = dp[i-1][j];
	            if(arr[i]<=j){
	                take = dp[i-1][j-arr[i]];
	            }
	            dp[i][j]= (take+notTake)%mod;
	        }
	    }
	    return dp[n-1][sum];
	}

//Space Optimization
int f(int sum,int arr[],int n,vector<int>&dp){
	    dp[0]=1;
	    if(arr[0]<=sum){ 
	        dp[arr[0]]=1;
	        if(arr[0]==0){
	            dp[arr[0]]++;
	        }
	    }
	    for(int i=1;i<n;i++){
	        vector<int>temp(sum+1,0);
	        temp[0]=1;
	        for(int j=0;j<=sum;j++){
	            int take=0;
	            int notTake = dp[j];
	            if(arr[i]<=j){
	                take = dp[j-arr[i]];
	            }
	            temp[j]= (take+notTake)%mod;
	        }
	        dp=temp;
	    }
	    return dp[sum];
	}
