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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* fr=new ListNode(0,head),*st=fr;
        while(st){
            int pre=0;
            ListNode* en=st->next;
            while(en){
                pre+=en->val;
                if(pre==0)st->next=en->next;
                en=en->next;
            }
            st=st->next;
        }
        return fr->next;
    }
};