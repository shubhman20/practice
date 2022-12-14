//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool checkc(vector<int>&stall,int &cows,int &key){
        int cnt(1),coordi=stall[0];
        for(int i=1;i<stall.size();i++){
            if(stall[i]-coordi>=key){
                cnt++;
                coordi=stall[i];
            }
            if(cnt==cows)return 1;
        }
        return 0;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int l=1,h=stalls[n-1]-stalls[0],res(1);
        
        while(l<=h){
            int mid = (h-l)>>1;
            mid+=l;
            
            if(checkc(stalls,k,mid)){
                res=max(res,mid);
                l=mid+1;
            }else
                h=mid-1;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
