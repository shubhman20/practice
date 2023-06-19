//TC----->O(n) , SC----->O(1)
bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int n = t.size();
        int m = s.size();
        while(i<n && j<m){
            if(t[i]==s[j]){
                j++;
            }
            i++;
        }
        return j==m;
    }
