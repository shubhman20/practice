//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL) return ans;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            Node *curr = q.front().first;
            int val = q.front().second;
            q.pop();
            mp[val]=curr->data;
            
            if(curr->left){
                q.push({curr->left,val-1});
            }
            
            if(curr->right){
                q.push({curr->right,val+1});
            }
        }
        
        for(auto &it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
