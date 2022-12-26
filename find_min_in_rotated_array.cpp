class Solution {
public:
    int pivot(vector<int>& a){
        int l=0,h=a.size()-1;
        int mid;
        while(l<h){
            mid = l + (h-l)/2;
            if(a[0]<=a[mid]&&a[mid]>a[h])
                l=mid+1;
            else{
                h=mid;
            }
        }
        return l;
    }

    int findMin(vector<int>& nums) {
        int idx = pivot(nums);
        return nums[idx];
    }
};
