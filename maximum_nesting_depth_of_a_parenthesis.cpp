class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                curr++;
                cnt=max(cnt,curr);
            }
            else if(s[i]==')')
                curr--;
            // cnt=max(cnt,curr);
        }
        return cnt;
    }
};
