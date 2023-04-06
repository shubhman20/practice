/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node *root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
    void leafBoundary(Node *root,vector<int>&ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
                ans.push_back(root->data);
        }
        leafBoundary(root->left,ans);
        leafBoundary(root->right,ans);
    }

    void leftBoundary(Node *root,vector<int> &ans){
        if(root==NULL) return;
        Node *curr = root;
        while(curr!=NULL){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left!=NULL){
                curr = curr->left;
            }
            else{
                curr= curr->right;
            }
        }
    }
    
    void rightBoundary(Node *root,vector<int> &temp){
        if(root==NULL) return;
        Node *curr=root;
        while(curr!=NULL){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right!=NULL){
                curr = curr->right;
            }
            else{
                curr= curr->left;
            }
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL) return ans;
        ans.push_back(root->data);
        if(root->left==NULL&&root->right==NULL) return ans;
        leftBoundary(root->left,ans);
        leafBoundary(root,ans);
        vector<int> temp;
        rightBoundary(root->right,temp);
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[temp.size()-1-i]);
        }
        return ans;
        
        
    }
};
