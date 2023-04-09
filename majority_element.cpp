//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int ele=a[0];
        int cnt=1;
        for(int i=1;i<size;i++){
            if(cnt==0){
                ele=a[i];
            }
            if(a[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int val=0;
        for(int i=0;i<size;i++){
            if(a[i]==ele){
                val++;
            }
        }
        if(val<=size/2){
            return -1;
        }
        return ele;
        
    }
};
