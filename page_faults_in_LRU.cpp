//TC----->O(N*C) , SC----->O(C)
int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<N;i++){
            if(mp.find(pages[i])!=mp.end()){
                mp[pages[i]]=i;
            }
            else{
                mp[pages[i]]=i;
                cnt++;
            }
            
            if(mp.size()>C){
                int mini=INT_MAX;
                for(auto &it:mp){
                    mini=min(mini,it.second);
                }
                mp.erase(pages[mini]);
            }
            
        }
        return cnt;
    }
