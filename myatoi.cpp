class Solution {
public:
    long long ans=0;
    int val=1;
    void convert(int idx,string s){
        if(idx>=s.size()||(s[idx]<'0'||s[idx]>'9'))
            return;
        if(ans*10>=INT_MAX || (ans*10+(s[idx]-'0'))>INT_MAX){
            if(val==-1){
                ans=INT_MIN;
            }
            else{
                ans=INT_MAX;
            }
            return;
        }
            
        ans = ans*10 + (s[idx]-'0');
        convert(idx+1,s);
    }

    int myAtoi(string s) {
        // int val=1;
        int i=0;
        while(s[i]==' '&&i<s.size()){
            i++;
        }
        if(s[i]=='-'){
            val=-1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        
        convert(i,s);
        if(ans==INT_MIN)
            return ans;
        return val*ans;
        
    }
};
