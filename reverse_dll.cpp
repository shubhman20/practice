/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
Node* reverseDLL(Node * head)
{
    //Your code here
    Node*temp=NULL;
    if(head==NULL)
        return head;
    while(head->next!=NULL){
        // temp = head;
        head->prev=head->next;
        head->next=temp;
        temp=head;
        head = head->prev;
    }
        head->prev=head->next;
        head->next=temp;
        temp=head;
    return head;
    
    
}
