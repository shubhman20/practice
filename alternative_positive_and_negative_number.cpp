//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos;
	    vector<int> neg;
	    int flag=1;
	   // if(arr[0]>=0) flag=1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0) pos.push_back(arr[i]);
	        if(arr[i]<0) neg.push_back(arr[i]);
	    }
	    int i=0,j=0,k=0;
	    while(i<pos.size() && j<neg.size()){
	        if(flag==1){
	            arr[k++]=pos[i++];
	            flag=0;
	        }
	        else{
	            arr[k++]=neg[j++];
	            flag=1;
	        }
	    }
	    
	    //for remaining postive numbers
	    while(i<pos.size()){
	        arr[k++]=pos[i++];
	    }
	    
	    //for remaining negative numbers
	    while(j<neg.size()){
	        arr[k++]=neg[j++];
	    }
	}
};
