//Tabulation
class Solution{
	public:
	int f(int n,int m,string s1,string s2,vector<vector<int>>&dp){
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
	            else{
	                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    return dp[n][m];
	}
	
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    int k = f(n,m,str1,str2,dp);
	    return (n-k)+(m-k);
	    
	} 
};


//Everything is same just we need to make a slight change in the main function
