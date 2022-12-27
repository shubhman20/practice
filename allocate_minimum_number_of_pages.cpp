//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool ispossible(int barrier,int avail,int a[],int n){
        int allocate=1,pages=0;
        for(int i=0;i<n;i++){
            if(a[i]>barrier) return false;
            if(pages+a[i]>barrier){
                allocate++;
                pages=a[i];
            }
            else{
                pages+=a[i];
            }
        }
        if(allocate>avail)
            return false;
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N)
            return -1;
        if(N==1&&M==1)
            return A[0];
        int l = A[0],h=0;
        for(int i=0;i<N;i++){
            h+=A[i];
        }
        int mid,res=-1;
        while(l<=h){
            mid = l + (h-l)/2;
            if(ispossible(mid,M,A,N)){
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
