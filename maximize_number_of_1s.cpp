class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int i=0,j=0;
        int cnt=0,ans=0;
        while(j<n && i<n){
            if(arr[i]==1){
                cnt++;
                i++;
            }
            else if(arr[i]==0 && m>0){
                m--;cnt++;
                i++;
            }
            else{
                
                while(m<1 && j<n){
                    if(arr[j]==0){
                        m++;
                    }
                    j++;
                }
                cnt = i-j;
            }
            ans=max(ans,cnt);
        }
        return ans;
        
    }  
};
