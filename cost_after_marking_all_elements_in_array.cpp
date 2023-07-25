class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(!pq.empty()){
            int idx = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            if(nums[idx]!=val){
                continue;
            }
            nums[idx]=-1;
            if(idx-1>=0){
                nums[idx-1]=-1;
            }
            if(idx+1<n){
                nums[idx+1]=-1;
            }
            ans+=val;
        }
        return ans;
    }
};
