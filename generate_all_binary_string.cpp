/*QUESTION:- 
Given an integer N , generate all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.

Example 1:

Input:
N = 3
Output:
000 , 001 , 010 , 100 , 101
Explanation:
None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively.

*/




//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void create(string &a,int num,vector<string>&ans){
        if(num<=0){
            ans.push_back(a);
            return;
        }
        if(a[a.size()-1]=='1'){
            a.push_back('0');
            create(a,num-1,ans);
            a.pop_back();
        }
        else{
            a.push_back('0');
            create(a,num-1,ans);
            a.pop_back();
            a.push_back('1');
            create(a,num-1,ans);
            a.pop_back();
        }
    }


    void generateBinaryStrings(int& num){
        //Write your code
        vector<string>ans;
        string a="0";
        string b="1";
        create(a,num-1,ans);
        create(b,num-1,ans);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        
    }
};

/*ANOTHER SOLUTION
void helper(string str, int i, int prev, int n){
        if(i==n){
           cout << str << " ";
           return;
        }
        
        if(prev==-1){
            helper(str+'0',i+1,0,n);
            helper(str+'1',i+1,1,n);
        }
        else if(prev==0){
            helper(str+'0',i+1,0,n);
            helper(str+'1',i+1,1,n);
        }
        else {
             helper(str+'0',i+1,0,n);
        }
    }
    
    void generateBinaryStrings(int& num){
        int i = 0;
        int n = num;
        helper("",i,-1,n);
    }
};
*/

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
