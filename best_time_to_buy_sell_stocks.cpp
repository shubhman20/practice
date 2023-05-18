//Recursion
int f(int idx,vector<int> &prices,int val){
        if(idx<0) return 0;
        if(prices[idx]< val) return max(f(idx-1,prices,val),val-prices[idx]);
        return f(idx-1,prices,prices[idx]);

    }

//Memoization
int f(int idx,vector<int> &prices,int val,vector<int>&dp){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        if(prices[idx]< val) return dp[idx]=max(f(idx-1,prices,val,dp),val-prices[idx]);
        return dp[idx]=f(idx-1,prices,prices[idx],dp);

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n,-1);
        return f(n-2,prices,prices[n-1],dp);
    }

//Tabulation
int f(int n,vector<int> &prices,vector<int>&dp){
        int val = prices[0];
        for(int i=1;i<=n;i++){
            if(prices[i-1]>val) dp[i] = max(dp[i-1],prices[i-1]-val);
            else{
                dp[i]=dp[i-1];
                val=prices[i-1];
            }
        }
        return dp[n];
    }

//Space Optimization
int f(int n,vector<int> &prices){
        int prev=0,curr=0;
        int val = prices[0];
        for(int i=1;i<=n;i++){
            if(prices[i-1]>val) curr = max(prev,prices[i-1]-val);
            else{
                curr=prev;
                val=prices[i-1];
            }
            prev=curr;
        }
        return prev;
    }
