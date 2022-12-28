class Solution {
public:
    string removeOuterParentheses(string s) {
        if(s.size()==0)
            return "";
        string ans="";
        for(int i=0;i<s.size();i++){
            int cnt=0;
            string a="";
            if(s[i]=='('){
                i++;cnt++;
                while(cnt&&i<s.size()){
                    if(s[i]=='(')
                        cnt++;
                    else if(s[i]==')')
                        cnt--;
                    if(cnt==0)
                        break;
                    a = a+s[i];
                    i++;
                }
                ans+=a;
            }
        }
        return ans;
    }
};
