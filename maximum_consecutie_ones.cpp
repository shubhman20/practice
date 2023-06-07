int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int zeroCnt=0,i=0,ans=0;
        // int n = nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                zeroCnt++;
            }
            if(zeroCnt>k){
                while(zeroCnt>k){
                    if(nums[i]==0) zeroCnt--;
                    i++;
                }
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
