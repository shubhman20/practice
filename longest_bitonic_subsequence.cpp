int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int ans=1;
	    int n = nums.size();
	    vector<int> increase(n,1),decrease(n,1);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(increase[j]+1>increase[i] && nums[i]>nums[j]){
	                increase[i] = increase[j] + 1;
	            }
	        }
	    }
	    vector<int> rev = nums;
	    reverse(rev.begin(),rev.end());
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(decrease[j]+1>decrease[i] && rev[i]>rev[j]){
	                decrease[i] = decrease[j] + 1;
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        if(increase[i]+decrease[n-i-1]-1>ans){
	            ans=increase[i]+decrease[n-i-1]-1;
	        }
	    }
	    
	    
	    return ans;
	}

//Better Approach
int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int ans=1;
	    int n = nums.size();
	    vector<int> increase(n,1),decrease(n,1);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(increase[j]+1>increase[i] && nums[i]>nums[j]){
	                increase[i] = increase[j] + 1;
	            }
	        }
	    }
	    //reverse the direction of nested loop
	    for(int i=n-1;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(decrease[j]+1>decrease[i] && nums[i]>nums[j]){
	                decrease[i] = decrease[j] + 1;
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(increase[i]+decrease[i]-1>ans){
	            ans=increase[i]+decrease[i]-1;
	        }
	    }
	    
	    
	    return ans;
	}
