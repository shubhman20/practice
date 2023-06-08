//TC----->O(2*n) , SC----->O(n)
int characterReplacement(string S, int K) {
        // code here
        int n = S.size();
        int ans=0,l=0,r=0,maxCount=0;
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++){
            mp[S[r]-'a']++;
            maxCount = max(maxCount,mp[S[r]-'a']);
            while(r-l+1-maxCount>K){
                mp[S[l]-'a']--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
