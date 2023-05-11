/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(head==NULL)
      {
          return NULL;
      }
      //复制
      Node* cur=head;
      while(cur!=NULL){
          Node* s= new Node(cur->val);
          s->next=cur->next;
          cur->next=s;
          cur=s->next;
      }

      //构建random指向
      cur=head;
      while(cur!=NULL){
          if(cur->random!=NULL){
              cur->next->random=cur->random->next;
          }
          cur=cur->next->next;
      }

      //拆分
      Node* ans=head->next;
      cur=head;
      while(cur!=nullptr){
          Node* tmp = cur->next;
            cur->next = tmp->next;
            if (tmp->next != nullptr) {
                tmp->next = tmp->next->next;
            }
            cur = cur->next;
      }
      tmp->next=nullptr;
      return ans;

    }
};