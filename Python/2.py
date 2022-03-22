
# first que

# n = int(input())
# w = int(input())

# l = list(map(int,input().split()))

# print(l)

# for i in range(n) : 
#     l[i] = (l[i])/w

# print(l)
# i = l.index(max(l))
# print(i+1)


# second que

# n = int(input())

# l1 = list(map(int,input().split()))
# l2 = list(map(int,input().split()))

# print( abs( sum(l2) - sum(l1)) )


# 3rd question


# d = {}
# def numberOfWays(n,m) : 
#     if d.get(f'{n}{m}') : 
#         return d.get(f'{n}{m}')
#     if n==1 or m ==1 :
#         return 1
#     ans =  numberOfWays(n-1,m) + numberOfWays(n,m-1)
#     d[f'{n}{m}'] = ans
#     return ans
# n = int(input())
# m = int(input())
# x = int(input())
# y = int(input())
# print( numberOfWays(n,m) - numberOfWays(x,y) )


# 4th que
# n = input()
# k = int(input())

# while True : 
#     if (len(n) <= k ) :
#         print(0)
#         break

#     i = 0
#     ans = ''
#     while i < len(n)-1 and k > 0 : 
#         if int(n[i]) > int(n[i+1]) : 
#             i+=1
#             k-=1
#             continue
#         else: 
#             ans += n[i]
#             i+=1
#     ans += n[i]
#     i+=1

#     if k > 0 : 
#         ans = ans[:-k]


#     if i <= len(n)-1 : 
#         while i < len(n) : 
#             ans += n[i]
#             i+=1
    
#     print(int(ans))

#     break

# que 6

# from xml.dom import InuseAttributeErr


# n = int(input())
# l = list(map(int,input().split()))
# t = int(input())

# ans = 0
# for x in l : 
#     ans += 1
#     if x > t : 
#         ans += 1

# print(ans)


# que 7

# l = list(map(int,input().split(',')))

# num1 = -8
# num2 = 0

# isBtn = False

# for x in l : 
#     if x == 5 : 
#         isBtn = True
#     elif x == 8 : 
#         isBtn = False

#     if isBtn : 
#         num2 = num2*10 + x
#     else :
#         num1 += x

# print(num1 + (num2*10+8))


# que 8

# from grpc import AuthMetadataContext


# n1 = int(input())
# n2 = int(input())

# l = [x for x in range(n1,n2+1)]
# lst = []
# # [1,2,3,4]
# for i in range(len(l)+1) : 
#     for j in range(i) : 
#         lst.append(l[j:i])

# ans = 0
# for x in lst : 
#     if  sum(x) % 2 != 0  : 
#         ans += 1

# print(ans)


# que 9

# array = list(map(int,input(). split(",")))
# array=sorted(array)
# j = []
# j.append(array[0])
# j.append(array[1])

# for i in range(2,len(array)):
#     if j[i-1]+j[i-2] in array:
#         j.append(j[i-1]+j[i-2])
#     else:
#        break
 
# print(j)

# que 10

# n = input()
# d = {}

# ans = ''
# for i in range(0,len(n)) : 
#     x = n[i]
#     if x >= 'a' and x<='z' : 
#         ans += x 
#     else : 
#         d[i]=n[i]

# ans = list(ans[::-1])
# for i,j in d.items() : 
#     ans.insert(i,j)

# print("".join(ans))


# que 11
# word manipulation

# s = list(input())
# l = []
# check = [1]*len(s)
# for i in range(len(s)) :
#     temp = []
#     if s[i] != '@' : 
#         temp.append(s[i])
#     for j in range(i+1,len(s)) : 
#         if s[j] != '@' : 
#             if ( s[i].upper() == s[j].upper() ) :
#                 temp.append(s[j])
#                 s[j] = '@'
#     if len(temp) != 0 : 
#         l.append("".join(temp))

# d = {}
# for i in range(len(l)) :  
#     d[l[i].upper()] = l[i]
# l = sorted([x.upper() for x in l])
# for i,j in d.items() : 
#     t = l.index(i)
#     l[t] = j
# i = 0
# j = len(l)-1
# ans = ''
# while i<=j : 
#     if i == j : 
#         ans += l[i]
#     else : 
#         ans += l[i] + l[j]
#     i+=1
#     j-=1

# print(ans)

# que 12

# from itertools import combinations


# l = list(map(int,input().split(',')))
# x = int(input())
# l = list(combinations(l,4))
# c = 0
# for i in l : 
#     if sum(i) == x  : 
#         c+=1

# print(c)

# que 13

# from operator import le


# r,c = map(int,input().split(' '))
# l = []
# for _ in range(r) : 
#     l.append(list(map(str,input().split(' '))))

# cnt = 0
# for i in range(r-1) : 
#     for j in range(c-1) : 
#         a = int(l[i][j]) % sum(list(map(int,l[i][j])))
#         b = int(l[i][j+1]) % sum(list(map(int,l[i][j+1])))
#         cl = int(l[i+1][j]) % sum(list(map(int,l[i+1][j])))
#         d = int(l[i+1][j+1]) % sum(list(map(int,l[i+1][j+1])))

#         if a == 0 and b ==0 and cl ==0 and d == 0 : 
#             print(l[i][j], l[i][j+1])
#             print(l[i+1][j], l[i+1][j+1])


# que 14

# def palindrom (n) : 
#     nr = n[::-1]
#     return nr == n

# n = input()
# while True : 
#     if palindrom(n) : 
#         print(len(n))
#         break

#     n = str(int(n) + int(n[::-1]))

# que 15

# (4+3)*(12/6)+100

# print(int(eval(input())))

# que 16 

# s = input()
# ans = ''
# for i in range(len(s)) : 
#     if i%2 != 0 : 
#         ans += str(int(s[i])**2)
# print(ans[:4])









