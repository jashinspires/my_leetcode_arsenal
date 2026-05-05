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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1 ; 
        ListNode* tail = head ;
        if(head == nullptr || head-> next == nullptr || k == 0 ){
            return head;
        }
        while(tail->next != nullptr){
            tail = tail->next;
            n++;
        }
        tail -> next = head ;
        int total_cuts = n - (k%n);
        ListNode* newtail = head;
        for(int i = 1 ; i < total_cuts ; i++){
            newtail = newtail->next;
        }
        ListNode* Newhead = newtail->next;
        newtail->next = nullptr ;
        return Newhead;


    }
};