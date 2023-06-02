string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        int n = pre_exp.size();
        for(int i=n-1;i>=0;i--){
            if( (pre_exp[i]>='a' && pre_exp[i]<='z') || (pre_exp[i]>='A' && pre_exp[i]<='Z')||(pre_exp[i]>='0' && pre_exp[i]<='9')){
                string s = "";
                s+=pre_exp[i];
                st.push(s);
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push('('+op1+pre_exp[i]+op2+')');
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
