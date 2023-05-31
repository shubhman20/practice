vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //Initialising two vectors one for storing the longest divisible subset till that index and one is for backtracking and get the elements in the longest divisible subset   
        vector<int> dp(n,1),hash(n);
        int lastIdx=0;
        int maxi=1;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<=i-1;j++){
                if(dp[j]+1>dp[i] && nums[i]%nums[j]==0){
                    dp[i] = dp[j] + 1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIdx=i;
            }
        }

        vector<int> ans;
        //Storing all divisible elements in longest divisible subset 
        while(hash[lastIdx]!=lastIdx){
            ans.push_back(nums[lastIdx]);
            lastIdx=hash[lastIdx];
        }
        ans.push_back(nums[lastIdx]);
        return ans;
    }
