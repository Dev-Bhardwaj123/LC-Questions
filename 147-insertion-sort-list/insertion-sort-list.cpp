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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        ListNode* curr=head;
        while(curr!=nullptr){
            v.push_back(curr->val);
            curr=curr->next;
        }
        sort(v.begin(),v.end());
        int i=0;
        curr=head;
        while(curr!=nullptr){
            curr->val=v[i++];
            curr=curr->next;
        }
        return head;
    }
};