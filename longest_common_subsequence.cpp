//Recursion
int f(int idx1,int idx2,string s1,string s2){
        if(idx1<0||idx2<0) return 0;
        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]=1 + f(idx1-1,idx2-1,s1,s2);
        }
        
        return dp[idx1][idx2]=max(f(idx1-1,idx2,s1,s2),f(idx1,idx2-1,s1,s2));
    }

//Memoization
int f(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp){
        if(idx1<0||idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]=1 + f(idx1-1,idx2-1,s1,s2,dp);
        }
        
        return dp[idx1][idx2]=max(f(idx1-1,idx2,s1,s2,dp),f(idx1,idx2-1,s1,s2,dp));
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x,vector<int>(y,-1));
        return f(x-1,y-1,s1,s2,dp);
    }

//Tabulation
 int f(int x,int y,string s1,string s2,vector<vector<int>>&dp){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=1;
                    if(i>0&&j>0) dp[i][j]+=dp[i-1][j-1];
                }
                else{
                    int a=0,b=0;
                   if(i>0) a= dp[i-1][j];
                   if(j>0) b=dp[i][j-1];
                   dp[i][j]=max(a,b);
                }
            }
        }
        return dp[x-1][y-1];
    }

//Space Optimization
int f(int x,int y,string s1,string s2,vector<int>&dp){
        for(int i=0;i<x;i++){
            vector<int> temp(y,0);
            for(int j=0;j<y;j++){
                if(s1[i]==s2[j]){
                    temp[j]=1;
                    if(i>0&&j>0) temp[j]+=dp[j-1];
                }
                else{
                    int a=0,b=0;
                   if(i>0) a= dp[j];
                   if(j>0) b=temp[j-1];
                   temp[j]=max(a,b);
                }
            }
            dp=temp;
        }
        return dp[y-1];
    }
