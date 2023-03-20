class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int i=0,j=0;
        int val=nums[0];
        for(i=1;i<nums.size();i++){
            if(nums[i]==val){
                j=i;
                while(j<nums.size()&&nums[j]==val){
                    j++;
                }
                nums.erase(nums.begin()+i,nums.begin()+j);
            }
            val=nums[i];
        }
        return nums.size();
    }
};
