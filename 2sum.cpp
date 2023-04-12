class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        //to store answer
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int val=target - nums[i];
            if(mp.find(val)!=mp.end()){
                ans.push_back(mp[val]);
                ans.push_back(i);
                return ans;
            }
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};
