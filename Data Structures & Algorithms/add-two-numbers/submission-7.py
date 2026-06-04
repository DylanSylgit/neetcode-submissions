# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        ret = ListNode(0)
        ptr1 = l1
        ptr2 = l2
        ptr3 = ret

        addOne = 0

        while ptr1 or ptr2:
            value = 0

            if ptr1 and ptr2: value = ptr1.val + ptr2.val + addOne
            elif ptr1: value = ptr1.val + addOne
            elif ptr2: value = ptr2.val + addOne

            if value >= 10:
                ptr3.next = ListNode(((value - 10)))
                addOne = 1
            else:
                ptr3.next = ListNode((value))
                addOne = 0
            if ptr1: ptr1 = ptr1.next
            if ptr2: ptr2 = ptr2.next
            ptr3 = ptr3.next
        if addOne != 0:
            ptr3.next = ListNode(1)
        return ret.next
            
