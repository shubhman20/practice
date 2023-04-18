// #define ll long long
class Solution{
public:
    ll mod = 1e9+7;
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<ll>>ans(n+1);
        ans[0].push_back(1);
        if(n==1) return ans[0];
        // ans[1].push_back(1);
        // ans[1].push_back(1);
        // if(n==2) return ans[1];
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(j==0||j==i-1){
                    ans[i].push_back(1);
                }
                else{
                    ll val = (ans[i-1][j-1]+ans[i-1][j])%mod;
                    ans[i].push_back(val);
                }
            }
        }
        return ans[n];
    }
};
