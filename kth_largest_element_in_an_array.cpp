class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        k = n-k;
        while(k){
            pq.pop();
            k--;
            if(k==0)
                return pq.top();
        }
        return pq.top();
    }
};
