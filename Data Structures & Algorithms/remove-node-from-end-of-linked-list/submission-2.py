# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0,head)
        start = head
        length = 0
        
        while start:
            start = start.next
            length+=1
        index = length - n
        currI = 0
        start = dummy
        prev = None

        while currI <= index:
            prev = start
            start = start.next
            nxt = start.next
            currI +=1

        prev.next = start.next
        

        return dummy.next
        