class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        sort(strs.begin(),strs.end());
        // string pre= strs[0];
        int v = strs[0].size();
        for(int i=0;i<strs.size();i++){
            string k=strs[i];
            // string temp="";/
            int j;
            for(j=0;j<v;j++){
                if(strs[0][j]==k[j])
                    continue;
                else
                    break;
            }
            if(j==0) return "";
            v=j;
        }
        return strs[0].substr(0,v);
    }
};
