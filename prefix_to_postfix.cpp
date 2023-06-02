string preToPost(string pre_exp) {
        int n = pre_exp.size();
        stack<string> st;
        for(int i=n-1;i>=0;i--){
            if((pre_exp[i]>='a' && pre_exp[i]<='z') || (pre_exp[i]>='A' && pre_exp[i]<='Z') || (pre_exp[i]>='0' && pre_exp[i]<='9')){
                string op = "";
                 op+= pre_exp[i];
                st.push(op);
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push(op1 + op2 + pre_exp[i]);
            }
        }
        return st.top();
    }
