class Solution {
public:
    string largestOddNumber(string num) {
        if(num.size()==1){
            if((num[0]-'0')%2!=0)
                return num;
            else
                return "";
        }
        // string ans="";
        int i;
        for(i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                break;
            }
        }
        if(i>=0){
            return num.substr(0,i+1);
        }
        return "";
    }
};
