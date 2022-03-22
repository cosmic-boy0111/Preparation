# selection sort
# find the minimum element and swap with the first element
# no of iteration n-1


l = [12,45,23,51,19,8]
n = len(l)
# for i in range(0,n-1) : 
#     for j in range(i+1,n) : 
#         if l[j] < l[i] : 
#             temp = l[i]
#             l[i] = l[j]
#             l[j] = temp
    
# print(l)


# bubble sort
# compare adj elements and make their odder in right position
# iteration 5

# count = 1
# while count < n :
#     for i in range( n - count ) : 
#         if l[i] > l[i+1] : 
#             temp = l[i]
#             l[i] = l[i+1]
#             l[i+1] = temp
#     count += 1

# print(l)


# insertion sort
# insert ele at correct position
# iteration n

count = 1
while count < n  : 
    for i in range(count,0) : 
        if l[i] < l[i-1] : 
            temp = l[i]
            l[i] = l[i-1]
            l[i-1] = temp
        else : 
            break
    count +=1
print(l)

