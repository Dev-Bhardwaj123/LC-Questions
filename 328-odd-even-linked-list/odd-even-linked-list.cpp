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
        ListNode* od=nullptr;
        ListNode* od_end=nullptr;
        ListNode* ev=nullptr;
        ListNode* ev_end=nullptr;
        int i=1;
        for(ListNode* curr=head;curr!=nullptr;curr=curr->next){
            if(i%2!=0){
                if(od==nullptr){
                    od=curr;
                    od_end=od;
                }
                else{
                    od_end->next=curr;
                    od_end=curr;
                }
            }
            else{
                if(ev==nullptr){
                    ev=curr;
                    ev_end=curr;
                }
                else{
                    ev_end->next=curr;
                    ev_end=curr;
                }
            }
            i++;
        }
        if(od==nullptr || ev==nullptr){
            return head;
        }
        od_end->next=ev;
        ev_end->next=nullptr;
        return od;
        
    }
};