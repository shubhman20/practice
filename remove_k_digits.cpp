string removeKdigits(string S, int k) {
        int n = S.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>S[i]  && k>0){
                st.pop();
                k--;
            }
            
            if(st.empty() && S[i]=='0') continue;
            st.push(S[i]);
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
