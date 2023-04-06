//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	
    	vector<int> ans;
    	if(root==NULL) return ans;
    	queue<Node*> q;
    	q.push(root);
    	ans.push_back(root->data);
    	int flag=-1,cnt=1;
    	while(!q.empty()){
    	    vector<int> temp;
    	    int n = q.size();
    	    for(int i=0;i<n;i++){
    	        Node * var = q.front();
    	        q.pop();
    	        if(var->left!=NULL){
    	            q.push(var->left);
    	            temp.push_back(var->left->data);
    	        }
    	        if(var->right!=NULL){
    	            q.push(var->right);
    	            temp.push_back(var->right->data);
    	        }
    	    }
    	    if(flag==-1){
    	        reverse(temp.begin(),temp.end());
    	    }
    	    for(int i=0;i<temp.size();i++){
    	        ans.push_back(temp[i]);
    	    }
    	    flag= flag*(-1);
    	}
    	return ans;
    	
    }
};
