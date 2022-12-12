

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    if(head==NULL)
        return 0;
    if(head->next==NULL)
        return 0;
    Node*f=head->next;
    Node* s = head->next->next;
    int flag=0,ans=0;
    while(s!=NULL&&s->next!=NULL){
        f = f->next;
        s = s->next->next;
        if(f==s)
        {
            flag=1;
            break;
        }
    }
    if(flag==0){
        return 0;
    }
    else{
        f=head;
        ans=1;
        while(s!=f){
            f=f->next;
            s=s->next;
        }
        flag=0;
        s = s->next;
        while(s!=f){
           ans++;
           s=s->next;
            
        }
    }
    return ans;
}
