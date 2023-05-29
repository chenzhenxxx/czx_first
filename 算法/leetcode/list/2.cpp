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
       int clear=0;
       ListNode* tmp1 = l1;
       ListNode* tmp2 =l2;
       ListNode *dummyhead = new ListNode(0);
       ListNode *l3 = new ListNode(0);
       dummyhead=l3;
       while(tmp1&&tmp2){
           int sum=tmp1->val+tmp2->val+clear;
           clear=sum/10;
           sum=sum%10;
           ListNode * tmp = new ListNode(sum);
           l3->next=tmp;
           l3=tmp;
           tmp1=tmp1->next;
           tmp2=tmp2->next;
       }  
          
          while(tmp1){
              int sum = tmp1->val + clear;
              clear = sum/10;
              sum = sum%10;
              ListNode * tmp = new ListNode(sum);
              l3->next = tmp;
              l3=tmp;
              tmp1=tmp1->next;
          }
           while(tmp2){
              int sum = tmp2->val + clear;
              clear = sum/10;
              sum = sum%10;
              ListNode * tmp = new ListNode(sum);
              l3->next = tmp;
              l3=tmp;
              tmp2=tmp2->next;
          }
          if(clear!=0)
          {
              ListNode * tmp = new ListNode(clear);
              l3->next = tmp;
              l3=tmp;
          }
       l3->next=NULL;

       return dummyhead->next;
    }
};