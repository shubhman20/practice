class Solution {
public:
int pivot(vector<int>&nums,int n){
    int l=0;
    int h = n-1;
    int mid;
    while(l<h){
        mid = l + (h-l)/2;
        if(nums[0]<=nums[mid]){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    return l;
}

    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target) return 0;
            else{
                return -1;
            }
        }
        
        // // return idx;
        if(nums[0]==target) return 0;
        if(nums[nums.size()-1]==target) return nums.size()-1;
        int idx = pivot(nums,nums.size());       
        int l=0,h=nums.size()-1;
        if(idx!=0&&idx!=nums.size()-1){
            if(nums[idx]<=target && nums[nums.size()-1]>=target)
                l=idx;
            else{
                h=idx-1;
            }
        }
        int mid;
        while(l<h){
            mid = l + (h-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                l = mid+1;
            }
            else{
                h=mid-1;
            }

        }
        if(nums[l]==target)
            return l;
         return -1;
    }
};
