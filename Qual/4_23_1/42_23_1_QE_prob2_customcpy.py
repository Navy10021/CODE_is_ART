class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def list_to_linked_list(numlist:list)->ListNode:
    if not numlist:
        return None
    head = ListNode(numlist[0])
    curr = head

    for val in numlist[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

def printnode(head: ListNode)->None:
    while(head):
        print(head.val)
        head = head.next
    return

def printnode2(head: ListNode)->None:
    print("[", end='')
    curr = head
    while(curr):
        if (not curr.next):
            print(curr.val, end=']')
        else:
            print(curr.val, end=', ')
        curr = curr.next
        
def llcopy(head: ListNode) -> ListNode: #same with copy.deepcopy(head)
    if not head:
        return None

    # Start with a dummy node. 
    # This simplifies the loop as you don't need a condition for the head of the copied list.
    dummy = ListNode()
    current = dummy  # point to the dummy node

    while head:
        current.next = ListNode(head.val)  # create a new node for the copied list
        current = current.next  # move to the new node
        head = head.next  # move to the next node in the original list

    # return the node after dummy. This will be the head of the copied list.
    return dummy.next

def reverse(head: ListNode)-> ListNode:
    prev = None
    curr = llcopy(head)
    while(curr):
        next = curr.next # 임시저장
        curr.next = prev # 방향 바꾸기
        prev = curr # 전진
        curr = next # 전진

    return prev


def palindrome(s: ListNode) -> bool:
    curr = s
    rs = reverse(curr)
    while curr and rs:
        if curr.val == rs.val:
            curr = curr.next
            rs = rs.next
        else:
            return False
    return True



def substring(s:ListNode, t:ListNode) -> bool: # t in s:
    ss = s; tt = t
    if (not ss and tt): # s는 끝났는데 t가 남은 경우
        return False
    tmp = tt # 위치를 저장해둠. 같은 주소를 가리키지만, t가 전진하면 tmp는 그대로 있음.
    while(ss and tt): # 둘다 있는 경우
        if ss.val == tt.val:
            ss = ss.next
            tt = tt.next
            if (not ss and tt):
                return False
        else:
            tt = tmp
            if(not substring(ss.next, tt)):
                return False
            else:
                return True
    return True # s는 남았는데 t는 끝나는 경우 또는 둘다 끝나는 경우

def slicing(s:ListNode, st: int, en : int): # s[st:en] st부터 en-1까지..
    curr = llcopy(s)
    ct = 0
    while(ct < st):
        curr = curr.next
        ct += 1
    newhead = curr
    newcurr = curr
    while(ct < en-1):
        newcurr.next = curr.next
        curr = curr.next
        newcurr = newcurr.next
        ct += 1
    newcurr.next = None
    return newhead

def maxpalindrome(s:ListNode) -> None:
    n = 0
    curr = s
    curr2 = s
    out = []
    while(curr):
        curr = curr.next
        n += 1
    w = n # window size
    while (w):
        for i in range(n-w+1):
            subll = slicing(curr2, i, i+w)
            if palindrome(subll):
                include = 0
                for j in range(len(out)):
                    if substring(out[j], subll):
                        include = 1
                        break
                if (not include):
                    out.append(subll)
        w -= 1
    print("[", end = '')
    for i in range(len(out)):
        llcurr = out[i]
        printnode2(llcurr)
        if i == len(out) - 1:
            print("", end='')
        else:
            print(", ", end = '')
    print("]")

    return


if __name__ == "__main__":
    l1 = [1, 2, 3, 4, 5]; l1head = list_to_linked_list(l1)
    l2 = [1, 2]; l2head = list_to_linked_list(l2)
    l3 = [1, 3]; l3head = list_to_linked_list(l3)
    l4 = [3, 4]; l4head = list_to_linked_list(l4)
    l5 = [4, 5]; l5head = list_to_linked_list(l5)
    l6 = [3, 5]; l6head = list_to_linked_list(l6)
    p1 = [1, 2, 3, 2, 1]; p1head = list_to_linked_list(p1)
    p2 = [3]; p2head = list_to_linked_list(p2)
    p3 = [2, 3, 1]; p3head = list_to_linked_list(p3)
    p4 = [2, 3, 2]; p4head = list_to_linked_list(p4)
    p5 = [1, 2, 3, 2, 1, 3, 5, 3]; p5head = list_to_linked_list(p5)
    p6 = [3, 2, 1, 3, 5, 3]; p6head = list_to_linked_list(p6)
    # print(palindrome(p6head))
    s = "kabccbadzdefgfeda"
    s1 = list(s); s1head = list_to_linked_list(s1)
    ss1 = ["d", "z", "d"]; ss1head = list_to_linked_list(ss1)
    ss2 = ["d", "e", "f", "g", "f", "e", "d"]; ss2head = list_to_linked_list(ss2)
    s2 = list("kabccba dzabccbaza"); s2head = list_to_linked_list(s2)

    headlist = [l1head, l2head, l3head, l4head, l5head, l6head, p1head, p2head, p3head, p4head, p5head, l6head, s1head, s2head]
    for i in range(len(headlist)):
        print(i, end = ' ')
        maxpalindrome(headlist[i])