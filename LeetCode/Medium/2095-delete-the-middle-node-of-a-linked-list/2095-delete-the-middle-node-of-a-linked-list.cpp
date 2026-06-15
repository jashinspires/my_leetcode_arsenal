class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        
        ListNode* s = head;
        ListNode* f = head->next->next;
        
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        
        ListNode* t = s->next;
        s->next = s->next->next;
        delete t;
        
        return head;
    }
};