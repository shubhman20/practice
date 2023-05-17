//Recursion
int f(int idx1,int idx2,string &s,string &t){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        if(s[idx1]==t[idx2]) return (f(idx1-1,idx2-1,s,t)+f(idx1-1,idx2,s,t));
        return f(idx1-1,idx2,s,t);
    }

//Memoization
int f(int idx1,int idx2,string &s,string &t,vector<vector<int>>&dp){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==t[idx2]) return dp[idx1][idx2]=(f(idx1-1,idx2-1,s,t,dp)+f(idx1-1,idx2,s,t,dp));
        return dp[idx1][idx2]=f(idx1-1,idx2,s,t,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }

//Tabulation
int mod = 1e9 + 7;
    int f(int n,int m,string &s,string &t,vector<vector<int>>&dp){
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                else{
                    dp[i][j] = dp[i-1][j];
                }

            }
        }
        return dp[n][m];
    }

//Space Optimization
int mod = 1e9 + 7;
    int f(int n,int m,string &s,string &t,vector<int>&dp){
        dp[0]=1;
        for(int i=1;i<=n;i++){
            vector<int> temp(m+1,0);
            temp[0]=1;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) temp[j] = (dp[j-1] + dp[j])%mod;
                else{
                    temp[j] = dp[j];
                }
            }
            dp=temp;
        }
        return dp[m];
    }
