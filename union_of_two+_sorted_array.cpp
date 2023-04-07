class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of element
        vector<int> ans;
        int i=0,j=0,last=-1;
        while(i<n && j<m){
            int val;
            if(arr1[i]==arr2[j]){
                val =arr1[i];
                i++;j++;
            }
            else if(arr1[i]<arr2[j]){
                val=arr1[i];
                i++;
            }
            else if(arr2[j]<arr1[i]){
                val=arr2[j];
                j++;
            }
            
            if(last>=0){
                if(ans[last]!=val){
                    ans.push_back(val);
                    last++;
                }
            }
            else{
                ans.push_back(val);
                last++;
            }
        }
        
        while(i<n){
            int val = arr1[i];
            if(last>=0){
                if(ans[last]!=val){
                    ans.push_back(val);
                    last++;
                }
            }
            i++;
        }
        while(j<m){
            int val = arr2[j];
            if(last>=0){
                if(ans[last]!=val){
                    ans.push_back(val);
                    last++;
                }
            }
            j++;
        }
        return ans;
        
    }
};
