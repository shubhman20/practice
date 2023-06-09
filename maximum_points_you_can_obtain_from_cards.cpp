//TC----->O(n) , SC----->O(n)
 long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        long long ans=0,sum=0,val;
        vector<long long> Sum(N,0);
        for(int i=0;i<N;i++){
            sum+=cardPoints[i];
            Sum[i]=sum;
        }
        if(N==k) return sum;
        
        for(int i=0;i<=k;i++){
            int j = i + N - k - 1;
            if(i==0) val = Sum[j];
            else{
                val = Sum[j]-Sum[i-1];
            }
            ans = max(ans,sum-val);
        }
        
        return ans;
    }

//TC----->O(n) , SC----->O(1)
 long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        long long ans=0,val=0;
        for(int i=0;i<k;i++) ans+=cardPoints[i];
        val=ans;
        for(int i=k-1;i>=0;i--){
            val-=cardPoints[i];
            val+=cardPoints[N-k+i];
            ans = max(ans,val);
        }
        return ans;
    }
