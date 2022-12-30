class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int flg;
        for(int i=s.size()-1;i>=0;i--){
            int val,curr;
            if(s[i]=='I'){
                val=1;
            }
            else if(s[i]=='V'){
                val=5;
            }
            else if(s[i]=='X'){
                val=10;
            }
            else if(s[i]=='L'){
                val=50;
            }
            else if(s[i]=='C'){
                val=100;
            }
            else if(s[i]=='D'){
                val=500;
            }
            else{
                val=1000;
            }

            if(i==s.size()-1){
                ans+=val;
                flg=val;
            }
            else{
                if(flg>val){
                    ans-=val;
                }
                else{
                    ans+=val;
                }
            }
            flg=val;
        }
        return ans;

    }
};
