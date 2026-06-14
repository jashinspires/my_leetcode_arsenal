class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        int max_sum = 0;
        ListNode* first_half = head;
        ListNode* second_half = prev;
        
        while (second_half) {
            max_sum = max(max_sum, first_half->val + second_half->val);
            first_half = first_half->next;
            second_half = second_half->next;
        }
        
        return max_sum;
    }
};