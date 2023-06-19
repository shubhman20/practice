//TC----->O(2*n) , SC----->O(1)
int longestOnes(vector<int>& nums, int k) {
        int cntZero=0,i=0,j=0;
        int ans=0;
        int n = nums.size();
        while(i<n){
            if(cntZero==k && nums[i]==0){
                while(j<n && nums[j]!=0){
                    j++;
                }
                j++;
            }
            else if(nums[i]==0 && cntZero<k){
                cntZero++;
            }

            if(cntZero==k){
                ans = max(ans,i-j+1);
            }
            i++;
        }
        if(cntZero<k) return nums.size();
        return ans;
    }
