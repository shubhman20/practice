class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n2<n1){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l = 0,h=n1;
        int flag=0;
        if((n1+n2)%2!=0)
            flag=1;
        int mid;
        while(l<=h){
            mid = (l+h)/2;
            int cut1 = mid;
            int cut2= (n1+n2+1)/2-cut1;
            double l1 = cut1==0?INT_MIN:nums1[cut1-1];
            double l2 = cut2==0?INT_MIN:nums2[cut2-1];
            double r1 = cut1==n1?INT_MAX:nums1[cut1];
            double r2 = cut2==n2?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1){
                if(flag==0){
                    return ((max(l1,l2)+min(r1,r2))/2);
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                h=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
};
