//TC----->O(2*n) , SC----->O(1)
int totalFruits(int N, vector<int> &fruits) {
        int l=0,ans=0,r=0;
        unordered_map<int,int> mp;
        while(r<N){
            mp[fruits[r]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
