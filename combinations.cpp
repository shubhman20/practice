class Solution {
public:
    vector<vector<int>>ans;

    void f(int val ,int n,int k,vector<int>&temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }

        if(val>n){
            return;
        }

        //notTake
        f(val+1,n,k,temp);
        //take
        temp.push_back(val);
        f(val+1,n,k-1,temp);
        temp.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        f(1,n,k,temp);
        return ans;
    }
};
