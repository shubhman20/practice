vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        st.push(arr[n-1]);
        vector<long long> ans(n);
        ans[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            if(st.top()>arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && st.top()<=arr[i]){
                    st.pop();
                }
                if(st.empty()) ans[i]=-1;
                else{
                    ans[i]=st.top();
                }
                st.push(arr[i]);
            }
        }
        return ans;
    }
