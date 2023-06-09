//TC----->O(n) , SC----->O(26)~O(1)
int longestKSubstr(string s, int k) {
    // your code here
        int n = s.size();
        int l=0,ans=-1;
        unordered_map<char,int> mp;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()==k) ans = max(ans,r-l+1);
        }
        return ans;
    }
