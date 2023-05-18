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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return nullptr;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(slow!=fast)
        {
           if(fast==NULL||fast->next==NULL)return nullptr;

           slow=slow->next;
           fast=fast->next->next;

        }
        slow=slow->next;
        ListNode *ptr=head;
        while(ptr!=slow)
         {
             ptr=ptr->next;
            slow=slow->next;
        }
        return ptr;

    }
};