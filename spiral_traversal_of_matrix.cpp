class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int top=0,bottom=n-1;
        int left=0,right=m-1;
        while(top<=bottom && left<=right){
            //for left to right
            for(int i=left;i<=right;i++){
                // cout<<a[top][i]<<" ";
                --k;
                if(k==0){
                    return a[top][i];
                }
            }
            top++;
            //for top to bottom
            for(int i=top;i<=bottom;i++){
                --k;
                if(k==0){
                    return a[i][right];
                }
                // cout<<a[i][right]<<" ";
            }
            right--;
            //for right to left
            for(int i=right;i>=left;i--){
                // cout<<a[bottom][i]<<" ";
                --k;
                if(k==0){
                    return a[bottom][i];
                }
            }
            bottom--;
            //for bottom to top
            for(int i=bottom;i>=top;i--){
                // cout<<a[i][left]<<" ";
                --k;
                if(k==0){
                    return a[i][left];
                }
            }
            left++;
            
            
        }
        return 0;
    }

};
