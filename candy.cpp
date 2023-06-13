//TC----->O(3*N) , SC----->O(N)
int minCandy(int N, vector<int> &ratings) {
        // code here
        vector<int>candy(N,1);
        //iteration for right greater element
        for(int i=1;i<N;i++){
            if(ratings[i]>ratings[i-1]) candy[i] = candy[i-1]+1;
        }
        //iteration for left greater element
        for(int i=N-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) candy[i] = max(candy[i],candy[i+1]+1);
        }
        
        //calculating total candy required
        int ans=0;
        for(int i=0;i<N;i++){
            ans+=candy[i];
        }
        return ans;
    }
