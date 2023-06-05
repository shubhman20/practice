//TC----->O(n) + O(n) , SC----->O(n) + O(n) 
vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        if(N==1) return asteroids;
        stack<int> st;
        for(int i=0;i<N;i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                if(st.empty() || st.top()<0) st.push(asteroids[i]);
                else{
                    while(!st.empty() && st.top()>0 && st.top()<(-1)*asteroids[i]){
                        st.pop();
                    }
                    if(st.empty()||st.top()<(-1)*asteroids[i]) st.push(asteroids[i]);
                    else if(st.top()==(-1)*asteroids[i]){
                        st.pop();
                    }
                }
            }
        }
        vector<int>ans(0);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
