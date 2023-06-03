//TC----->O(n) , SC-----> O(1)
long long trappingWater(int arr[], int n){
        // code here
        int l=0,r=n-1;
        long long maxLeft=0,maxRight=0,ans=0;
        while(l<=r){
            if(arr[l]<=arr[r]){
                if(arr[l]>=maxLeft) maxLeft=arr[l];
                else{
                    ans+=(maxLeft-arr[l]);
                }
                l++;
            }
            else{
                if(arr[r]>=maxRight) maxRight=arr[r];
                else{
                    ans+= (maxRight-arr[r]);
                }
                r--;
            }
        }
        return ans;
        
    }
