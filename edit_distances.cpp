//recursion
int f(int idx1,int idx2,string &s,string &t){
        if(idx1<0) return idx2+1;
        if(idx2<0) return idx1+1;
        if(s[idx1]==t[idx2]) return f(idx1-1,idx2-1,s,t);
        return 1 + min(min(f(idx1-1,idx2,s,t),f(idx1,idx2-1,s,t)),f(idx1-1,idx2-1,s,t));
}
//Memoization
int f(int idx1,int idx2,string &s,string &t,vector<vector<int>>&dp){
        if(idx1<0) return idx2+1;
        if(idx2<0) return idx1+1;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==t[idx2]) return dp[idx1][idx2]=f(idx1-1,idx2-1,s,t,dp);
        return dp[idx1][idx2]=1 + min(min(f(idx1-1,idx2,s,t,dp),f(idx1,idx2-1,s,t,dp)),f(idx1-1,idx2-1,s,t,dp));
}
  
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }

//Tabulation
int f(int n,int m,string &s,string &t,vector<vector<int>>&dp){
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }

//Space Optimization
int f(int n,int m,string &s,string &t,vector<int>&dp){
        for(int j=0;j<=m;j++) dp[j]=j;
        
        for(int i=1;i<=n;i++){
            vector<int> temp(m+1,0);
            temp[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    temp[j] = dp[j-1];
                }
                else{
                    temp[j] = 1 + min(dp[j],min(dp[j-1],temp[j-1]));
                }
            }
            dp=temp;
        }
        return dp[m];
    }
