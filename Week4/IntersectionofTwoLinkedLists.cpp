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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            
            if(headA == nullptr || headB == nullptr ) return nullptr;
            
            int nA=0,nB=0,i=0;
            
            ListNode *curA=headA;
            while(curA!=nullptr){ curA=curA->next;nA++;}
            ListNode *curB = headB;
            while(curB!=nullptr){ curB=curB->next;nB++;}
            
            curB=headB; curA=headA;
            if(nB>nA){
                    while(i<(nB-nA)) { curB=curB->next; i++;}
            }
            else{
                    while(i<(nA-nB)) { curA=curA->next; i++;}
            }
            
            while(curA!=nullptr && curB!=nullptr){
                    if(curA == curB) return curA;
                    
                    curA=curA->next;
                    curB=curB->next;
            }
            
            return nullptr;        
    }
};