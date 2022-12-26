class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(nums.size()==1)
            return nums[0];
        else{
            
            while(l<h){
                if(nums[l]!=nums[l+1])
                    return nums[l];
                if(nums[h]!=nums[h-1])
                    return nums[h];
                l=l+2;
                h=h-2;
            }
        }
        return nums[l];
    }
};
