//TC----->O(2*n) , SC----->O(1)
int longestSubarray(vector<int>& nums) {
        int ans=0,cnt=0;
        int i=0,j=0;
        int n = nums.size();
        while(i<n){
            if(nums[i]==0 && cnt==1){
                while(j<n && nums[j]!=0){
                    j++;
                }
                j++;
            }
            else if(nums[i]==0){
                cnt++;
            }
            ans = max(ans,i-j);
            i++;
        }
        return ans;
    }
