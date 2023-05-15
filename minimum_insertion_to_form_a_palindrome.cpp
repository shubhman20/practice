//Recursion
    int lcp(int idx1,int idx2,string s1,string s2){
        if(idx1<0||idx2<0) return 0;
        if(s1[idx1]==s2[idx2]) return 1 + lcp(idx1-1,idx2-1,s1,s2);
        return max(lcp(idx1-1,idx2,s1,s2),lcp(idx1,idx2-1,s1,s2));
    }
    int countMin(string str){
    //complete the function here
    int n = str.size();
    string t = str;
    reverse(t.begin(),t.end());
    return n-lcp(n-1,n-1,str,t);
    }
//Memoization
int lcp(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp){
        if(idx1<0||idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) return dp[idx1][idx2]=1 + lcp(idx1-1,idx2-1,s1,s2,dp);
        return dp[idx1][idx2]=max(lcp(idx1-1,idx2,s1,s2,dp),lcp(idx1,idx2-1,s1,s2,dp));
    }
    int countMin(string str){
    //complete the function here
    int n = str.size();
    string t = str;
    reverse(t.begin(),t.end());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return n-lcp(n-1,n-1,str,t,dp);
    }

//Tabulation
    int lcp(int n,int m,string s1,string s2,vector<vector<int>>&dp){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=1;
                    if(i>0&&j>0) dp[i][j]+=dp[i-1][j-1];
                }
                else{
                    int val1=0,val2=0;
                    if(i>0) val1 = dp[i-1][j];
                    if(j>0) val2 = dp[i][j-1];
                    dp[i][j]=max(val1,val2);
                }
            }
        }
        return dp[n-1][m-1];
    }
    
    int countMin(string str){
    //complete the function here
    int n = str.size();
    string t = str;
    reverse(t.begin(),t.end());
    vector<vector<int>> dp(n,vector<int>(n,0));
    return n-lcp(n,n,str,t,dp);
    }

//Space Optimization
int lcp(int n,int m,string s1,string s2,vector<int>&dp){
        for(int i=0;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(s1[i]==s2[j]){
                    temp[j]=1;
                    if(i>0&&j>0) temp[j]+=dp[j-1];
                }
                else{
                    int val1=0,val2=0;
                    if(i>0) val1 = dp[j];
                    if(j>0) val2 = temp[j-1];
                    temp[j]=max(val1,val2);
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
    
    int countMin(string str){
    //complete the function here
    int n = str.size();
    string t = str;
    reverse(t.begin(),t.end());
    vector<int> dp(n,0);
    return n-lcp(n,n,str,t,dp);
    }
