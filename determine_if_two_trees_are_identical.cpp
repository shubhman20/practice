/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool Identical(Node *root1,Node *root2){
        if(root1==NULL&&root2==NULL) return true;
        else if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL)||(root1->data!=root2->data)){
            return false;
        }
        
        
        bool left=Identical(root1->left,root2->left);
        bool right=Identical(root1->right,root2->right);
        if(root1->data!=root2->data) return false;
        return left&&right;
        
    }
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        return Identical(r1,r2);
        
    }
};
