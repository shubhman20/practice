/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middle(ListNode*head){
        if(head==NULL) return head;
        ListNode* s;
        ListNode* f;
        s=head;
        f=head->next;
        while(f!=NULL&&f->next!=NULL){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    ListNode* merge(ListNode* l,ListNode* h){
        if(l==NULL) return h;
        if(h==NULL) return l;
        ListNode* ans = new ListNode(-1);
        // ans->next=NULL;
        ListNode* temp = ans;
        while(l!=NULL&&h!=NULL){
            if(l->val<h->val){
                temp->next=l;
                temp=l;
                l=l->next;
            }
            else{
                temp->next=h;
                temp=h;
                h=h->next;
            }
        }
        while(l!=NULL){
            temp->next=l;
            temp=l;
            l = l->next;
        }
        while(h!=NULL){
            temp->next=h;
            temp=h;
            h=h->next;
        }
        return ans->next;
    }
    ListNode* mergeSort(ListNode*head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* mid = middle(head);
        ListNode* l = head;
        ListNode* h = mid->next;
        mid->next=NULL;
        l=mergeSort(l);
        h=mergeSort(h);
        ListNode* a= merge(l,h);
        return a;
    }

    ListNode* sortList(ListNode* head) {
        // ListNode* mid
        if(head==NULL||head->next==NULL) return head;
        head=mergeSort(head);
        return head;

    }
};
