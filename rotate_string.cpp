class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        int j=0;
        for(int k=0;k<s.size();k++){
            if(goal[j]==s[k])
                j++;
        }
        int k=0;
        for(;j<goal.size();j++){
            if(goal[j]==s[k])
            {
                k++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
