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
    ListNode* reverseKGroup(ListNode* head, int k) {
       // Check if there are at least k nodes to reverse
        ListNode* check = head;
        int count = 0;
        while (check != nullptr && count < k) {
            check = check->next;
            count++;
        }
        // If we have less than k nodes left, we do not reverse them
        if (count < k) return head;
        ListNode* curr=head,*nextie=nullptr,*prev=nullptr;
        int cnt=0;
        while(curr!=nullptr && cnt<k){
            nextie=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextie;
            cnt++;
        }
        if(nextie!=nullptr){
            head->next=reverseKGroup(nextie,k);
            
        }
        return prev;
    }
};