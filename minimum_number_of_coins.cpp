// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        int curr[10] = {1,2,5,10,20,50,100,200,500,2000};
        int idx=9;
        while(N>0&&idx>=0){
            if(N<curr[idx]){
                idx--;
            }
            else{
                int k = N/curr[idx];
                N = N - k*curr[idx];
                while(k--){
                    ans.push_back(curr[idx]);
                }
                idx--;
            }
        }
        return ans;
    }
};
