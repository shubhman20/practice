
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int fpos=-1,lpos=-1;
        int l=0,h=nums.size()-1;
        int mid;
        //firstposi
        while(l<=h){
            mid = l + (h-l)/2;
            if(nums[mid]==target){
                fpos=mid;
                h=mid-1;
                
            }
            else if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                h=mid-1;
        }
        //lastposi
        l=0,h=nums.size()-1;
        while(l<=h){
            mid = l + (h-l)/2;
            if(nums[mid]==target){
                lpos=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                h=mid-1;
        }
        ans.push_back(fpos);
        ans.push_back(lpos);
        return ans;
    }
};
