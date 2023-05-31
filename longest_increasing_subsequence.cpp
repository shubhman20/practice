//Recursion
int f(int idx,int n,int prevIdx,vector<int>&nums){
        if(idx==n) return 0;
        int notTake = f(idx+1,n,prevIdx,nums);
        int take=0;
        if(prevIdx==-1 || nums[idx]>nums[prevIdx]) take = 1 + f(idx+1,n,idx,nums);
        return max(take,notTake);
    }

//Memoization
int f(int idx,int n,int prevIdx,vector<int>&nums,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][prevIdx+1]!=-1) return dp[idx][prevIdx+1];
        int notTake = f(idx+1,n,prevIdx,nums,dp);
        int take=0;
        if(prevIdx==-1 || nums[idx]>nums[prevIdx]) take = 1 + f(idx+1,n,idx,nums,dp);
        return dp[idx][prevIdx+1] = max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,n,-1,nums,dp);
    }

//Tabulation
int f(int n,vector<int>&nums,vector<vector<int>>&dp){
        for(int idx=n-1;idx>=0;idx--){
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
                int length =dp[idx+1][prevIdx+1];
                if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
                    length = max(length,1+dp[idx+1][idx+1]);
                }
                dp[idx][prevIdx+1] = length;
            }
        }
        return dp[0][0];
    }

//Space Optimization
 int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n+1,0), curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
                int length =prev[prevIdx+1];
                if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
                    length = max(length,1+prev[idx+1]);
                }
                curr[prevIdx+1] = length;
            }
            prev=curr;
        }
        return prev[0];
    }


//Another Approach
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp(n,1);
       int maxi=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<=i-1;j++){
               if(a[j]<a[i]){
                   dp[i] = max(dp[i],1+dp[j]);
               }
               if(dp[i]>maxi) maxi=dp[i];
           }
       }
       return maxi;
    }
