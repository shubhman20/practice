
//Better Approach TC----->O(2*n) , SC----->O(n)
 int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        int rightSum=0;
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if(prefixSum[i] - rightSum==nums[i]) idx=i;
            rightSum+=nums[i];
        }
        return idx;
    }

//Optimal Approach TC----->O(2*n) , SC----->O(1)
 int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum=0;
        for(int i=0;i<n;i++){
            rightSum-=nums[i];
            if(rightSum==leftSum) return i;
            leftSum+=nums[i];
        }
        return -1;
    }
