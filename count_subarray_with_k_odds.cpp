//TC----->O(n) , SC----->O(n)
int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int ans=0,l=0,odd=0;
        vector<int> prefix(n+1,0);
        for(int r=0;r<n;r++){
            prefix[odd]++;
            
            if(nums[r]&1) odd++;
            
            if(odd>=k) ans+=prefix[odd-k];
        }
        return ans;
    }
