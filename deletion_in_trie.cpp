/*Complete the function below
Node is as follows:
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
    
};*/
class Solution{
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
    //Code here
    int n = strlen(key);
    for(int i=0;i<n;i++){
        if(!root->children[key[i]-'a']) return;
        root = root->children[key[i]-'a'];
    }
    root->value=0;
  }
};
