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
    ListNode* reverseKGroup(ListNode* head, int k) {
           
            if(head ==  nullptr) return head;
            
            return reverseKNodes(head,k);                                    
    }
        
      ListNode* reverseKNodes(ListNode* node, int K, ListNode* prev=nullptr)
      {
              if(node==nullptr) return nullptr;
              int c=0;
              
              ListNode* cur=node;
              while(c<K && cur!=nullptr)
              {
                  ListNode* temp = cur->next;
                  cur->next = prev;    
                  prev= cur;
                  cur = temp;
                  c++;    
              }
                                          
              node->next = reverseKNodes(cur,K,node);
              
              if(c!=K) {
                      reverseKNodes(prev,c,nullptr);
                      return node;
              }
              
              return prev;
      }  
};