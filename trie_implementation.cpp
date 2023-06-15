class Node{
    Node *link[26];
    bool flag=false;
public:
    bool containKey(char ch){
        return (link[ch-'a']!=NULL);
    }

    void insertKey(char ch,Node *node){
        link[ch-'a']=node;
    }

    Node *get(char ch){
        return link[ch-'a'];
    }

    void setFinal(){
        flag=true;
    }

    bool checkFlag(){
        return flag==true;
    }

};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    //O(word length)
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containKey(word[i])){
                node->insertKey(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setFinal();
    }
    //O(word length)
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->checkFlag();
    }
    //O(preix length)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return node!=NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
