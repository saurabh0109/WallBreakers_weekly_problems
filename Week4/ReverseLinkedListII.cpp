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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
      if(head == nullptr || n==m) return head;
      
      ListNode *cur = head, *prev=nullptr;
      int count=0;
      
      while(cur!=nullptr && count<m-1)
      {
        prev=cur;
        cur=cur->next;
        count++;
      }
      
      if(cur==nullptr) return head;
      
      if(prev!=nullptr)
      {
        prev->next = reverseNnodes(cur,n-m+1);      
        return head;
      }
      else
        return reverseNnodes(cur,n-m+1);
        
    }
  
    ListNode* reverseNnodes(ListNode* head, int n)
    {
      if(head == nullptr) return head;
      
      ListNode *prev = nullptr, *cur = head;
      int count=0;
      
      while(count < n && cur!=nullptr){
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        count++;
      }
      
      head->next = cur;
      return prev;
    }
};