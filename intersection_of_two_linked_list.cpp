/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count(ListNode* a){
        ListNode* t;
        t=a;
        int cnt=0;
        while(t!=NULL){
            t=t->next;
            cnt++;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = count(headA);
        int b = count(headB);
        ListNode* h1;
        ListNode* temp;
        ListNode* brokelink;
        if(a<=b){
            h1=headB;
            temp=h1;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            brokelink=temp;
            temp->next=headA;
        }
        else{
            h1=headA;
            temp=h1;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            brokelink=temp;
            temp->next=headB;
        }
        if(h1==NULL||h1->next==NULL)
            return h1;
        ListNode* h2=h1->next->next;
        temp=h1->next;
        while(h2!=NULL&&h2->next!=NULL&&temp!=h2){
            temp=temp->next;
            h2=h2->next->next;
        }
        if(h2==NULL||h2->next==NULL){
            brokelink->next=NULL;
            return NULL;
        }
        h2=h1;
        while(temp!=h2){
            temp=temp->next;
            h2=h2->next;
        }
        brokelink->next=NULL;
        return temp;
        
    }
};
