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
    ListNode* deleteNode(ListNode* head, int val) {
       ListNode * dummyhead = new ListNode(0);
       
       dummyhead->next = head;
       ListNode * tmp = dummyhead;
       while(dummyhead->next){
           if(dummyhead->next->val == val){
               dummyhead->next=dummyhead->next->next;
               break;
           }
           dummyhead=dummyhead->next;
       }
       return tmp->next;
    }
};