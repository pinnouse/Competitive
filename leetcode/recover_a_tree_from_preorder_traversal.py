# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
# #         self.right = right
# class Q:
#     def __init__(self):
#         self.q = [None] * 1000
#         self.i = 0
#         self.l = 0
    
#     def e(self, o):
#         self.q.append(o)
#         self.l += 1
        
#     def d(self):
#         o = self.q[self.i]
#         self.i += 1
#         return o
    
# class S:
#     def __init__(self):
#         self.s = [None] * 1000
#         self.l = 0
        
#     def pu(self, o):
#         self.s[self.l] = o
#         self.l += 1
        
#     def po(self):
#         o = self.s[self.l - 1]
#         self.l -= 1
#         return o
    
def int_extract(t: str) -> Tuple[int, str]:
    s = ''
    for c in t:
        if c == '-':
            break
        s += c
    if len(s) == 0:
        return (-1, t)
    return (int(s), t[len(s):])
    
def helper(t: str, d: int) -> Tuple[Optional[TreeNode], str]:
    if len(t) == 0:
        return None, t
    for i in range(d):
        if t[i] != '-':
            return None, t
    # Else we have a root
    v, trunc = int_extract(t[d:])
    if v == -1:
        return None, t
    t = trunc
    # trunc = '' if len(t) == 0 else t[1:]
    # if len(t) == 0 or t[0] == '-':
    #     return (None, trunc)
    r = TreeNode(v)
    r.left, t = helper(t, d + 1)
    r.right, t = helper(t, d + 1)
    return (r, t)

class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        return helper(traversal, 0)[0]