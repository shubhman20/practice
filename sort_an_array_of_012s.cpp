class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int left=0,mid=0,right=n-1;
        while(mid<=right){
            if(a[mid]==0){
                swap(a[left],a[mid]);
                left++;mid++;
            }
            else if(a[mid]==1){
                mid++;
            }
            else if(a[mid]==2){
                swap(a[mid],a[right]);
                right--;
            }
        }
    }
    
};
