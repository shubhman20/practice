//TC----->O(nlogn) , SC----->O(1)
int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int waiting=0,prevComp=0;
        int n = bt.size();
        for(int i=0;i<n;i++){
            waiting+=prevComp;
            prevComp+=bt[i];
        }
        return waiting/n;
    }
