//TC----->O(n) , SC----->O(1)
bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int first=nums[0];
        int second =INT_MAX;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<=first) first = nums[i];
            else if(nums[i]<=second) second = nums[i];
            else{
                return true;
            }
        }
        return false;
    }
