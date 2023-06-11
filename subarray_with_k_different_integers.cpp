//TC----->O(4*n) , SC----->O(n)
int atMostK(vector<int> &arr,int N,int k){
        vector<int>mp(N+1,0);
        int diff=0,ans=0,j=0;
        for(int i=0;i<N;i++){
            if(mp[arr[i]]==0) diff++;
            mp[arr[i]]++;
            while(diff>k){
                mp[arr[j]]--;
                if(mp[arr[j]]==0) diff--;
                j++;
                
            }
            ans+=i-j+1;
        }
        return ans;
    }
  
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        return atMostK(arr,N,k)-atMostK(arr,N,k-1);
        
    }
