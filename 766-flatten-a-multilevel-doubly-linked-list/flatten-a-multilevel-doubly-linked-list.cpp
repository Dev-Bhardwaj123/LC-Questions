/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* findTail(Node* child){
        while(child->next!=nullptr){
            child=child->next;
        }
        return child;
    }
    Node* flatten(Node* head) {
        Node* curr=head;
        while(curr!=nullptr){
            if(curr->child!=nullptr){
                Node* tail=findTail(curr->child);
                if(curr->next!=nullptr){
                    curr->next->prev=tail;
                }
                tail->next=curr->next;
                curr->next=curr->child;
                curr->child->prev=curr;
                curr->child=nullptr;
            }
            curr=curr->next;
        }
        return head;
    }
};