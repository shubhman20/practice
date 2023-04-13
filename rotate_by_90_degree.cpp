
class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        int val = n/2;
        for(int i=0;i<val;i++){
            for(int j=0;j<n;j++){
                swap(matrix[j][i],matrix[j][n-1-i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>i){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    } 
};
