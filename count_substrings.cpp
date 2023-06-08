//TC----->O(n) , SC----->O(3)
int countSubstring(string s) {
        // Code here
        int l=0,ans=0;
        int n = s.size();
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++){
            mp[s[r]-'a']++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0){
                ans+=n-r;
                mp[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
