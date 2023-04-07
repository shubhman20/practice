/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL) return ans;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            Node * curr = q.front().first;
            int val = q.front().second;
            q.pop();
            if(mp.find(val)==mp.end()){
                mp[val]=curr->data;
            }
            
            if(curr->left){
                q.push({curr->left,val-1});
            }
            if(curr->right){
                q.push({curr->right,val+1});
            }
            
        }
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }

};
