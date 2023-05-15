//Recursion
 int f(int idx1,int idx2,string a,string b){
        if(idx1<0  || idx2<0) return 0;
        if(a[idx1]==b[idx2]) return 1 + f(idx1-1,idx2-1,a,b);
        return dp[idx1][idx2]=max(f(idx1-1,idx2,a,b),f(idx1,idx2-1,a,b));
    }

//Memoization
 int f(int idx1,int idx2,string a,string b,vector<vector<int>> &dp){
        if(idx1<0  || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(a[idx1]==b[idx2]) return 1 + f(idx1-1,idx2-1,a,b,dp);
        return dp[idx1][idx2]=max(f(idx1-1,idx2,a,b,dp),f(idx1,idx2-1,a,b,dp));
    }
  
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        string t = A;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        reverse(t.begin(),t.end());
        return f(n-1,n-1,A,t,dp);
    }

//Tabulation
int f(int n,int m,string a,string b,vector<vector<int>> &dp){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i]==b[j]){
                    dp[i][j]=1;
                    if(i>0&&j>0) dp[i][j]+= dp[i-1][j-1];
                }
                else{
                    int val1=0,val2=0;
                    if(i>0) val1 = dp[i-1][j];
                    if(j>0) val2 = dp[i][j-1];
                    dp[i][j] = max(val1,val2);
                }
            }
        }
        return dp[n-1][m-1];
    }

//Space Optimization
int f(int n,int m,string a,string b,vector<int> &dp){
        for(int i=0;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(a[i]==b[j]){
                    temp[j]=1;
                    if(i>0&&j>0) temp[j]+= dp[j-1];
                }
                else{
                    int val1=0,val2=0;
                    if(i>0) val1 = dp[j];
                    if(j>0) val2 = temp[j-1];
                    temp[j] = max(val1,val2);
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
