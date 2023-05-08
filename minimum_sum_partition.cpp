class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    vector<vector<int>> dp(n,vector<int>(sum+1,0));
	    for(int i=0;i<n;i++){
	        dp[i][0]=1;
	    }
	    dp[0][arr[0]]=1;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<=sum;j++){
	           bool notTake=dp[i-1][j];
	           bool take=false;
	           if(arr[i]<=j){
	               take=dp[i-1][j-arr[i]];
	           }
	           dp[i][j]=take|notTake;
	        }
	    }
	    int ans=INT_MAX;
	    for(int i=0;i<=sum;i++){
	        if(dp[n-1][i]){
	            ans = min(ans,abs((sum-i)-i));
	        }
	    }
	    return ans;
	    
	} 
};
