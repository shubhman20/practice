//Recursion TC-----> Exponential , SC-----> O(n)
int f(int i,int n,string &s){
        if(i==n) return 0;
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + f(j+1,n,s);
                minCost = min(minCost,cost);
            }
        }
        return minCost;
    }

//Memoization TC-----> O(n^2) , SC-----> O(n^2) + O(n)
bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }

    int f(int i,int n,string &s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + f(j+1,n,s,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }

    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n,-1);
        return f(0,n,str,dp)-1;
    }

//Tabulation TC-----> O(n^2) , SC-----> O(n^2)
 int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int k=i;k<n;k++){
                if(isPalindrome(i,k,str)){
                    int cost = 1 + dp[k+1];
                    minCost = min(minCost,cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0]-1;
    }
