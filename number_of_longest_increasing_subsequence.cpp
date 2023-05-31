int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]+1>dp[i] && nums[i]>nums[j]){
                    dp[i] = dp[j]+1;
                    cnt[i]=cnt[j];
                } 
                else if(dp[j]+1==dp[i] && nums[i]>nums[j]){
                    cnt[i] += cnt[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) ans+=cnt[i];
        }
        return ans;
    }
