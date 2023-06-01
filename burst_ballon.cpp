//Recursion TC---> O(Exponential) , SC-----> O(n)
 int f(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        int ans = INT_MIN;
        for(int k=i;k<=j;k++){
            int val = f(i,k-1,nums) + f(k+1,j,nums) + nums[i-1]*nums[k]*nums[j+1];
            if(val>ans) ans=val;
        }
        return ans;
    }

//Memoization TC-----> O(n^3) , SC-----> O(n^2) + O(n)
 int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MIN;
        for(int k=i;k<=j;k++){
            int val = f(i,k-1,nums,dp) + f(k+1,j,nums,dp) + nums[i-1]*nums[k]*nums[j+1];
            if(val>ans) ans=val;
        }
        return dp[i][j]=ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return f(1,n,nums,dp);
    }

//Tabulation TC-----> O(n^3) , SC-----> O(n^2)
int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int ans=0;
                for(int k=i;k<=j;k++){
                    int val = dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1];
                    if(val>ans) ans=val;
                }
                dp[i][j]=ans;
            }
        }

        return dp[1][n];
    }
