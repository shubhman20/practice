class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        int mid;
        while(l<h){
            mid = l + (h-l)/2;
            if(nums[mid+1]>nums[mid])
                l=mid+1;
            else{
                h=mid;
            }
        }
        return l;
    }
};
