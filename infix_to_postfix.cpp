string infixToPostfix(string s) {
        // Your code here
        string ans;
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
          //If s[i] == operand then simply push it in ans string
            if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0' && s[i]<='9')) ans.push_back(s[i]);
          //If an opening bracket is present then push it into the stack
            else if(s[i]=='(') st.push(s[i]);
          //If we found any closing bracket then simply pop elements until an opening bracket is found in the stack
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
          //otherwise we push operator into the stack while maintaining an operator precedence of low to high from top to bottom (Precedence : ^ > * == / > + == -
            else{
                if(st.empty()){
                    st.push(s[i]);
                }
                else{
                    if(s[i]=='^'){
                        while(!st.empty() && st.top()=='^'){
                            ans.push_back(st.top());
                            st.pop();
                        }
                        st.push(s[i]);
                    }
                    else if(s[i]=='*' || s[i]=='/'){
                            while(!st.empty()&&(st.top()=='^'||st.top()=='/'||st.top()=='*')){
                                ans.push_back(st.top());
                                st.pop();
                            }
                        st.push(s[i]);
                    }
                    else{
                            while(!st.empty() && (st.top()=='^'||st.top()=='*'||st.top()=='/'||st.top()=='+'||st.top()=='-')){
                                ans.push_back(st.top());
                                st.pop();
                            }
                        st.push(s[i]);
                    }
                }
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
