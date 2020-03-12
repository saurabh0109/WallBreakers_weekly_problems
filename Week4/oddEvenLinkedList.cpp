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
    ListNode* oddEvenList(ListNode* head) {
      if(head == nullptr || head->next == nullptr) return head;
      
      ListNode* evenhead = head->next;      
      
      ListNode *curodd = head, *cureven = head->next, *prevodd = nullptr;      
        
      while(curodd!=nullptr && cureven!=nullptr)
      {      
        if(curodd->next!=nullptr)
          curodd->next = curodd->next->next; 
        prevodd = curodd;
        curodd = curodd->next;  

        if(cureven->next != nullptr)
          cureven->next = cureven->next->next;
        cureven = cureven->next;          
      }  
      
      if(curodd!=nullptr) prevodd = curodd; 
      
      prevodd->next = evenhead;
      
      return head;
      
    }
};