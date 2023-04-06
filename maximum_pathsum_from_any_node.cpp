// User Fuction template for C++

class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int maxPath(Node *root,int &sum){
        if(root==NULL) return 0;
        int left = max(0,maxPath(root->left,sum));
        int right = max(0,maxPath(root->right,sum));
        sum = max(sum,left+right+root->data);
        return max(left,right)+root->data;
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
      
        if(root==NULL) return 0;
        int sum=INT_MIN;
        int dummy=maxPath(root,sum);
        return sum;
        
    }
};
