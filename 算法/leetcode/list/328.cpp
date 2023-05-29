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
    ListNode* oddEvenList(ListNode* head) {
       if(head == nullptr)
       return head;
       ListNode *evenhead = head->next;
       ListNode* j = head;
       ListNode* o = head->next;
       while(o&&o->next){
          
           j->next = o->next;
           j = j->next;
           o->next = j->next;
           o = o->next;
       }
       j->next = evenhead;
       return head;
    }
};