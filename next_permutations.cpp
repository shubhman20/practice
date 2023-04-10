// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx1=-1;
        for(int i=N-1;i>0;i--){
            if(arr[i-1]<arr[i]){
                idx1=i-1;break;
            }
        }
        int idx2=0;
        if(idx1!=-1){
            for(int i=N-1;i>0;i--){
                if(arr[i]>arr[idx1]){
                    idx2=i;break;
                }
            }
            swap(arr[idx1],arr[idx2]);
            idx1++;
            reverse(arr.begin() + idx1,arr.end());
        }
        else{
            reverse(arr.begin(),arr.end());
        }
        return arr;
    }
};
