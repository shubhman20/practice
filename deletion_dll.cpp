/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      //Your code here
      if(head_ref==NULL)
        return head_ref;
      if(x==1){
          head_ref->next->prev=NULL;
          Node*temp = head_ref->next;
          head_ref->next = NULL;
          head_ref =temp;
      }
      else{
          Node* curr=head_ref;
          Node* prev =NULL;
          int idx=1;
          while(idx<x){
              prev = curr;
              curr=curr->next;
              idx++;
          }
          if(curr->next==NULL){
              prev->next=NULL;
              delete curr;
          }
          else{
              prev->next=curr->next;
              curr->next->prev=prev;
              curr->prev=NULL;
              curr->next=NULL;
              delete curr;
          }
      }
      return head_ref;
      
    }
};
