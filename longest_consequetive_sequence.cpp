class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int n=nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int maxCount=0;
        for(auto &it:s){
            if(s.find(it-1)==s.end()){
                int cnt=1;
                int x=it;
                while(s.find(x+1)!=s.end()){
                    x +=1;
                    cnt++;
                }
                maxCount = max(maxCount,cnt);
            }
        }
        return maxCount;
    }
};
