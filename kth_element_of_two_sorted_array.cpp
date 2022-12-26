//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m>n){
            return kthElement(arr2,arr1,m,n,k);
        }
        int l= max(0,k-m),h=min(k,n);
        while(l<=h){
            int cut1=(l+h)/2;
            int cut2 = k - cut1;
            int l1 = cut1==0 ?INT_MIN:arr1[cut1-1];
            int l2 = cut2==0 ?INT_MIN:arr2[cut2-1];
            int h1 = cut1==n ?INT_MAX:arr1[cut1];
            int h2 = cut2==m ?INT_MAX:arr2[cut2];
            if(l1<=h2 && l2<=h1){
                return max(l1,l2);
            }
            if(l1>h2){
                h=cut1-1;
            }
            else if(l2>h1){
                l=cut1+1;
            }
            
        }
        return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
