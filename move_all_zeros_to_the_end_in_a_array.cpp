//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i=0,j=0;
	    while(arr[i]!=0 && i<n) i++;
	    j=i;
	    while(arr[j]==0 && j<n) j++;
	    while(i<n && j<n){
	        if(arr[i]==0 && arr[j]!=0){
	            swap(arr[i],arr[j]);
	            i++;j++;
	        }
	        else if(arr[i]!=0) i++;
	        else if(arr[j]==0) j++;
	    }
	}
};
