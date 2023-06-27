//TC----->O(n) , SC----->O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt=1,j=1;
        int val = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==val){
                cnt++;
                if(cnt>2){
                    while(i<n && nums[i]==val){
                        i++;
                    }
                    if(i==n) break;
                    val=nums[i];
                    cnt=1;
                }
            }
            else{
                cnt=1;
                val=nums[i];
            }
            nums[j++]=val;
        }
        return j;
    }
};
