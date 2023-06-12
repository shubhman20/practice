//TC----->O(max(NlogN,MlogM)) , SC----->O(1) 
int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        int cnt=0;
        int i=N-1,j=M-1;
        while(i>=0 && j>=0){
            if(sz[j]>=greed[i]){
                cnt++;i--;j--;
            }
            else{
                i--;
            }
        }
        return cnt;
    }
