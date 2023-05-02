class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int prev=1;
        int curr=2;
        for(int i=n-3;i>=0;i--){
            int temp = curr + prev;
            prev=curr;
            curr=temp;
        }
        return curr;
    }
};
