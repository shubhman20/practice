class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<long long,int> mp;
        long long sum=0;
        int ans=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            long long val = sum - K;
            if(mp.find(val)!=mp.end()){
                ans = max(ans,i-mp[val]);
            }
            if(sum==K){
                ans=max(ans,i+1);
            }
            
        }
        return ans;
        
    } 

};
