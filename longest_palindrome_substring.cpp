class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string ans="";
        for(int i=0;i<s.size();i++){
            int j=i-1,k=i+1;
            string temp = "";
            temp.push_back(s[i]);
            //for odd palindrome
            while(j>=0&&k<s.size()){
                if(s[j]==s[k]){
                    temp = s[j]+temp+s[k];
                    // temp.append(s[k]);
                }
                else{
                    break;
                }
                j--;k++;
            }
            //for even palindrome
            string even = "";
            j=i;k=i+1;
            while(j>=0 && k<s.size()){
                if(s[j]==s[k]){
                    even = s[j] + even+s[k];
                }
                else
                    break;
                j--;k++;
            }
            if(even.size()>ans.size()&&temp.size()<=even.size())
                ans=even;
            else if(temp.size()>ans.size()&&even.size()<temp.size())
                ans=temp;
        }
        return ans;
    }
};
