





from cmath import log


def solve(n,l1,l2):
    ans = []
    d = dict();
    for i in range(0,n):
        d[l1[i]] = [];
    
    for i in range(0,n):
        d[l1[i]].append(l2[i])

    for key, value in d.items():
        d[key] = sum(value)//len(value)
    

    for i in range(0,n):
        ans.append(l2[i]-d[l1[i]])

    return ans

n = int(input());
l1 = list(map(int,input().split(' ')));
l2 = list(map(int,input().split(' ')));

print(solve(n,l1,l2));

