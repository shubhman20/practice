//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        if(head==NULL){
            return head;
        }
        Node* temp;
        Node* t;
        temp=NULL;
        t=head;
        // int flag=0;
        while(t->next!=NULL){
            if(t->next->data==9&&t->data!=9){
                temp=t;
                // flag=1;
            }
            t=t->next;
        }
        if(t->data!=9){
            t->data = t->data+1;
            return head;
        }
        else{
            if(temp==NULL){
                Node* n = new Node(1);
                n->next=head;
                head=n;
                n=n->next;
                while(n!=NULL){
                    n->data=0;
                    n=n->next;
                }
            }
            else{
                temp->data = temp->data + 1;
                temp=temp->next;
                while(temp!=NULL){
                    temp->data=0;
                    temp = temp->next;
                }
            }
        }
        
        // return head of list after adding one
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
