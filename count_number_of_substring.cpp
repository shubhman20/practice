/*Done with simple implementation of string so it can give TLE look for DP solution*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	long long int ans=0;
    	int cnt[26];
    	for(int i=0;i<s.size();i++){
    	    int dist=0;
    	    memset(cnt,0,sizeof(cnt));
    	    for(int j=i;j<s.size();j++){
    	        if(cnt[s[j]-'a']==0)
    	            dist++;
    	        cnt[s[j]-'a']++;
    	        if(dist==k) 
    	            ans++;
    	    }
    	    
    	}
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
