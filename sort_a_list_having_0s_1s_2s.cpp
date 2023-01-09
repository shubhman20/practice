//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head==NULL||head->next==NULL) return head;
        Node *d0 = new Node(-1);
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);
        Node* t0;
        Node* t1;
        Node* t2;
        t0=d0;t1=d1;t2=d2;
        Node* t = head;
        while(t!=NULL){
            if(t->data==0){
                t0->next=t;
                t0=t;
                t=t->next;
                t0->next=NULL;
            }
            else if(t->data==1){
                t1->next=t;
                t1=t;
                t=t->next;
                t1->next=NULL;
            }
            else{
                t2->next=t;
                t2=t;
                t=t->next;
                t2->next=NULL;
            }
        }
        
        if(d1->next==NULL){
            if(d0->next==NULL){
                return d2->next;
            }
            else{
                t0->next=d2->next;
            }
        }
        else{
            t0->next=d1->next;
            t1->next=d2->next;
        }
        
        return d0->next;
        // Add code here
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
