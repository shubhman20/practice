//TC----->O(n) , SC----->O(n)
int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        int ans=0,val=0;
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++){
            val+=arr[i];
            if(val==target) ans++;
            if(mp.find(val-target)!=mp.end()) ans+=mp[val-target];
            mp[val]+=1;
        }
        
        return ans;
    }
