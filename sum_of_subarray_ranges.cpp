long long subarrayRanges(int N, vector<int> &arr) {
        // code here
        long long sum=0;
        int mini=0,maxi=0;
        for(int i=0;i<N;i++){
            mini = arr[i];
            maxi=arr[i];
            for(int j=i+1;j<N;j++){
                mini= min(mini,arr[j]);
                maxi=max(maxi,arr[j]);
                sum+=(maxi-mini);
            }
        }
        return sum;
        
    }
