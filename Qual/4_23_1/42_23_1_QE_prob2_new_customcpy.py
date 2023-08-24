'''
함수 목록
1. list to linked list
2. printnode
3. printnode2
4. printnode3
5. llcopy
6. reverse
7. palindrome
8. substring
9. slicing
10. cmpll
11. removefn 
12. maxpalindrome 
'''


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

def printnode3(pdlist:list)->None:
    print("[", end = '')
    for i in range(len(pdlist)):
        llcurr = pdlist[i]
        printnode2(llcurr)
        if i == len(pdlist) - 1:
            print("", end='')
        else:
            print(", ", end = '')
    print("]")

def llcopy(head: ListNode) -> ListNode: #same with copy.deepcopy(head) custom deepcopy
    if not head:
        return None

    dummy = ListNode()
    current = dummy 

    while head:
        current.next = ListNode(head.val)  
        current = current.next 
        head = head.next 

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


def palindrome2(s: ListNode) -> bool:
    curr = s
    rs = reverse(curr)
    while curr and rs:
        if curr.val == rs.val:
            curr = curr.next
            rs = rs.next
        else:
            return False
    return True

def palindrome(head: ListNode) -> bool:
    if head is None:
        return True

    # Find the Middle Node of the Linked List #
    slow = head
    fast = head

    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
    
    # Reverse the second half of the Linked List #
    prev = None
    curr = slow

    while curr:
        temp = curr.next # 임시저장
        curr.next = prev # 방향바꾸고
        prev = curr # 한칸씩 전진
        curr = temp # 한칸씩 전진
    
    # Compare the two halves to check for palindrome #

    first = head
    second = prev

    while second:
        if first.val != second.val:
            return False
        first = first.next
        second = second.next
    return True

def substring(s: ListNode, t: ListNode) -> bool:
    if not t:
        return True
    if not s:
        return False

    ptr_s = s

    while ptr_s:
        ptr_t = t
        tmp_s = ptr_s
        while tmp_s and ptr_t and tmp_s.val == ptr_t.val:
            tmp_s = tmp_s.next
            ptr_t = ptr_t.next
        if not ptr_t:
            return True
        ptr_s = ptr_s.next

    return False


def substring_(s:ListNode, t:ListNode) -> bool: # t in s:
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
    while(ct < en-1):
        curr = curr.next
        ct += 1
    curr.next = None # next를 없애서 slicing 해줌
    return newhead

def cmpll_(s:ListNode, t:ListNode)->bool: # 같으면 True, 다르면 False
    currs = s; currt = t
    while currs and currt:
        if currs.val != currt.val:
            return False
        else:
            currs = currs.next
            currt = currt.next
    if currs and not currt:
        return False
    if not currs and currt:
        return False
    return True

def cmpll(s:ListNode, t: ListNode) -> bool:
    currs = s; currt = t;
    while currs and currt:
        if currs.val != currt.val:
            return False
        else:
            currs = currs.next
            currt = currt.next
    if not currs and not currt:
        return True
    else:
        return False
    
def removefn(l: list, head: ListNode): # linked list를 포함하는 list에서 하나의 linked list를 제거하는 function.
    for hl in l: # head in list
        if cmpll(hl, head):
            l.remove(hl)
            return l

def maxpalindrome(s:ListNode) -> None:
    n = 0
    curr = s
    pdlist = []
    removestr = []
    while(curr):
        curr = curr.next
        n += 1 # s의 길이
    for st in range(n):
        pd = slicing(s, st, st+1)
        for en in range(1, n+1):
            if(palindrome(slicing(s, st, en))):
                pd = slicing(s, st, en)
        for i in range(len(pdlist)):
            if substring(pdlist[i], pd):
                pd = None
                break
            if substring(pd, pdlist[i]): # 반대로 pdlist[i]가 속할 수도 있음 
                removestr.append(pdlist[i])
        if pd:
            pdlist.append(pd)
    for rs in removestr:
        pdlist = removefn(pdlist, rs)
    # 출력
    printnode3(pdlist)
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
    s1 = list("kabccbadzdefgfeda"); s1head = list_to_linked_list(s1)
    s2 = list("kabccba dzabccbaza"); s2head = list_to_linked_list(s2)
    s3 = list("asdsa azazza"); s3head = list_to_linked_list(s3)
    s4 = list("kkak"); s4head = list_to_linked_list(s4)

    # printnode2(slicing(l1head, 1, 3))

    headlist = [l1head, l2head, l3head, l4head, l5head, l6head, p1head, p2head, p3head, p4head, p5head, p6head, s1head, s2head, s3head, s4head]
    llist = [l1, l2, l3, l4, l5, l6, p1, p2, p3, p4, p5, p6, s1, s2, s3, s4]
    for l, h in zip(llist, headlist):
        print(l, end = '\n-> result: ')
        maxpalindrome(h)
    c1 = [1, 2, 3]; c1head = list_to_linked_list(c1)
    c2 = [1, 2, 3]; c2head = list_to_linked_list(c2)
    c3 = [1, 2]; c3head = list_to_linked_list(c3)
    c4 = [1, 2, 3, 4]; c4head = list_to_linked_list(c4)
    c5 = [2, 3]; c5head = list_to_linked_list(c5)
    clist = [c2head, c3head, c4head, c5head]
    for h in clist:
        print(cmpll(c1head, h))
