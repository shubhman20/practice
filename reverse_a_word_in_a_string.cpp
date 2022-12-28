class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0)
            return "";
        if(s.size()==1)
            return s;
        string ans="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            string a="";
            int temp=0;
            while(s[i]==' ') i++;
            while(s[i]!=' '&&i<s.size()){
                a.push_back(s[i]);
                i++;
                temp=1;
            }
            if(cnt==0&&temp==1){
                ans=a;
                cnt++;
            }
            else if(temp==1&&cnt>0){
                ans = a+" "+ans;
            }
        }
        return ans;
    }
};
