//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        sort(A,A+N);
        int diff=INT_MAX;
        N=N-2;
        int ans;
        for(int i=0;i<N;i++){
            int j=i+1,k=N+1;
            while(j<k){
                int sum = (A[i]+A[j]+A[k]);
                if(diff>abs(X-sum)){
                    diff=abs(X-sum);
                    ans=sum;
                }
                if(sum>X){
                    k--;
                }
                else if(sum<X){
                    j++;
                }
                else{
                    return X;
                }
            }
        }
        return ans;
    }
};
