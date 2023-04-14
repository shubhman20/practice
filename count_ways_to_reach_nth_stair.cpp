class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    long long mod = (1e9+7);
    int countWays(int n)
    {
        // your code here
        if(n<=2) return n;
        long long prev =1,curr=2,ans;
        n-=2;
        for(int i=1;i<=n;i++){
            ans = (prev+curr)%mod;
            prev=curr%mod;
            curr=ans;
        }
        return ans%mod;
    }
};
