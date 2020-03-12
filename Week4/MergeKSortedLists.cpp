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
        
        ListNode* mergeKLists(vector<ListNode*>& lists) {
                        
            ListNode *l = new ListNode(0), *h = l;             
                        
            auto compare = [](ListNode* a, ListNode* b) { return (a->val > b->val); };
                
            priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
            for(int i=0;i<lists.size();i++)            
                if(lists[i] != nullptr) pq.push(lists[i]);            
            
            while(!pq.empty())
            {
                   ListNode* top = pq.top();
                   pq.pop();
                   if(top->next != nullptr) 
                           pq.push(top->next);
                   
                   l->next = top;     
                   l = l->next;
            }
                
            return h->next;        
    }
};