class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(),-1);
        stack<int> st;
        int n = nums.size();
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    nge[i]=st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};
