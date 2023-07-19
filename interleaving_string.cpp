class Solution {
public:
    int cnt=0;
    bool f(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(k==s3.size()){
            if(i==s1.size() && j==s2.size()) return true;
            return false;
        }
        if(i==s1.size() && j==s2.size()) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int n = s1.size(),m=s2.size();

        bool first=false,second=false;
        if(i<n && s1[i]==s3[k]){
            first=f(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j<m && s2[j]==s3[k]){
            second=f(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j][k]=first|second;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return f(s1,s2,s3,0,0,0,dp);
    }
};
