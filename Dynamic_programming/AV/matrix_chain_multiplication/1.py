n = 11


for i in range(2,n+1) : 
    check = True
    ans = 0
    for j in range(2,i) : 
        if(j%i ==0) : 
            check = False

            break
    if(check) : 
        print(i)
    


