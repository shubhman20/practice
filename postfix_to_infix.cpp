string postToInfix(string exp) {
        // Write your code here
        int n = exp.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if((exp[i]>='a'&&exp[i]<='z')||(exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9')){
                string val = "";
                val+= exp[i];
                st.push(val);
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push('('+op2+exp[i]+op1+')');
            }
        }
        return st.top();
    }
