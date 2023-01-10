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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy =new ListNode();
        ListNode *ans = dummy;
        ListNode *a = l1;
        ListNode *b = l2;
        int c =0;
        while(a!=NULL || b!=NULL||c!=0){
            int m = a?a->val:0;
            int n = b?b->val:0;
            int sum = m+n+c;
            ListNode *node = new ListNode(sum%10);
            c = sum/10;
            ans->next=node;
            ans=ans->next;
            a=a?a->next:NULL;
            b=b?b->next:NULL;
        }
        
        return dummy->next;
        
    }
};
