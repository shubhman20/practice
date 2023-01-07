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
    int count(ListNode* head){
        int count=0;
        ListNode* t=head;
        while(t!=NULL){
            t=t->next;
            count++;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        int val=count(head);
        val = val/2;
        ListNode*temp;
        temp=head;
        int count=0;
        while(count<val-1){
            count++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};
