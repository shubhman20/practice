class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int cnt=1;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	int ans=1;
    	while(i<n&&j<n){
    	    if(arr[i]<=dep[j]){
    	        cnt++;
    	        i++;
    	    }
    	    else{
    	        j++;
    	        cnt--;
    	    }
    	    ans=max(ans,cnt);
    	}
    	return ans;
    }
};
