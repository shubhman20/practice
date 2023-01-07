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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL) return NULL;
        if(head->next->next==NULL){
            ListNode*temp;
            // temp=head;
            temp=head->next;
            head->next=NULL;
            delete temp;
            return head;
        }
        ListNode* s = head->next;
        ListNode* f = head->next->next;
        while(f!=NULL && f->next!=NULL){
            s = s->next;
            f = f->next->next;
        }
        ListNode *t;
        t=head;
        while(t->next!=s){
            t = t->next;
        }
        t->next = s->next;
        delete s;
        return head;
    }
};
