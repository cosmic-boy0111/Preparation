from random import randrange
from wsgiref.validate import InputWrapper


def collectMaximumOranges(trees,n,queries,q):
    l = []
    for i in range(0,1000000000):
        l.append(0)
    for x in trees:
        l[x[0]] = x[1]
    preSum = []
    preSum.append(l[0]);
    for i in range(1,1000000000):
        preSum.append(preSum[len(preSum)-1] + l[i])

    return preSum
    


    
# n = int(input())
# q = int(input())

# tree = []
# qr = []

# for i in range(n):
#     x = int(input())
#     y = int(input())
#     tree.append([x,y])

# for i in range(q):
#     x = int(input())
#     y = int(input())
#     qr.append([x,y])

# print(collectMaximumOranges(tree,n,qr,q));
l = []
for i in range(0,1000000009):
    l.append(0)
print(l)


