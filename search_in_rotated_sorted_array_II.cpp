class Solution {
public:

    bool search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        int mid;
        while(l<=h){
            while(l+1<=h && nums[l]==nums[l+1]) l++;
            while(l<=h-1 && nums[h]==nums[h-1]) h--;
            mid = l + (h-l)/2;
            //if first half is sorted
            if(nums[mid]==target)
                return true;
            if(nums[l]<nums[mid]){
                if(nums[mid]>target&& target>=nums[l])
                    h=mid;
                else{
                    l=mid+1;
                }
            }
            else if(nums[l]>nums[mid]){
                if(nums[mid]<target && target<nums[l]){
                    l=mid+1;
                }
                else{
                    h=mid;
                }
            }
            else
            {
                l++;
            }
        }
        // if(nums[l]==target) return true;
        return false;
    }
};
