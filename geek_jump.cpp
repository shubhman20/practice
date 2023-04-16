/* <----------Tabulation---------->

class Solution {
  public:

    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        dp[1]=abs(height[0]-height[1])+dp[0];
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-2]+abs(height[i-2]-height[i]),dp[i-1] + abs(height[i-1]-height[i]));
        }
        return dp[n-1];
    }
};
*/

/*<----------Space Optimization------------->*/
class Solution {
  public:

    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        // vector<int> dp(n,INT_MAX);
        if(n==1) return 0;
        int two=0;
        int one=abs(height[0]-height[1])+two;
        for(int i=2;i<n;i++){
            int curr = min(two+abs(height[i-2]-height[i]),one + abs(height[i-1]-height[i]));
            two=one;
            one=curr;
        }
        return one;
    }
};
