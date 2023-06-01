//Recursion TC----->Exponential , SC----->O(n)
 int f(int i,int n,int k,vector<int> &a){
        if(i==n) return 0;
        int sum=0,maxSum=0,len=0;
        int maxi=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi,a[j]);
            sum = len*maxi + f(j+1,n,k,a);
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }

//Memoization TC----->O(n*k) , SC----->O(n) + O(n)
 int f(int i,int n,int k,vector<int> &a,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int sum=0,maxSum=0,len=0;
        int maxi=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi,a[j]);
            sum = len*maxi + f(j+1,n,k,a,dp);
            maxSum = max(maxSum,sum);
        }
        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,n,k,arr,dp);
    }

//Tabulation TC----->O(n*k) , SC----->O(n)
int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int sum=0,maxSum=0,len=0;
            int maxi=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi = max(maxi,arr[j]);
                sum = len*maxi + dp[j+1];
                maxSum = max(maxSum,sum);
            }
            dp[i]=maxSum;
        }

        return dp[0];
    }
