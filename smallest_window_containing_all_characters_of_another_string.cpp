string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> m1(26,0),m2(26,0);
        int n1 = s.size();
        int n2 = p.size();
        for(int i=0;i<n2;i++) m2[p[i]-'a']++;
        int mcnt=0,dmcnt=n2;
        string ans="";
        int i=0,j=0;
        while(i<n1){
            //adding 
            if(mcnt<dmcnt){
                while(i<n1 && mcnt<dmcnt){
                    m1[s[i]-'a']++;
                    if(m1[s[i]-'a']<=m2[s[i]-'a']) mcnt++;
                    i++;
                }
            }
            //collecting and releasing
            while(mcnt==dmcnt && j<i){
                string pans = s.substr(j,i-j);
                if(ans.size()==0 || pans.size()<ans.size()) ans=pans;
                m1[s[j]-'a']--;
                if(m1[s[j]-'a']<m2[s[j]-'a']) mcnt--;
                j++;
            }
        }
        
        if(ans.size()==0) return "-1";
        return ans;
    }
