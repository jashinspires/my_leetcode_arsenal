# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if(  head == None or  head.next == None or k == 0):
            return head
        c = 1 
        tail = head
        while tail.next:
            tail = tail.next
            c += 1
        tail.next = head
        effective_cut = c - (k%c)
        new_tail = head
        for i in range(1,effective_cut):
            new_tail = new_tail.next
        new_head = new_tail.next
        new_tail.next = None
        return new_head

        