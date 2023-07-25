class Solution {
public:

    int f(int col,int row,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row==0) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int val = INT_MAX;
        for(int i=0;i<grid.size();i++){
            if(i!=col){
                val = min(val,grid[row][col]+f(i,row-1,grid,dp));
            }
        }
        return dp[row][col]=val;

    }


    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,f(i,n-1,grid,dp));
        }
        return ans;
    }
};
