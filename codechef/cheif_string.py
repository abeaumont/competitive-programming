for _ in range(int(input())):
    string = input()
    count_xy = 0
    count_yx = 0
    j=0
    for i in range(0,len(string)-1):
        if j<len(string)-1:
            
            if(string[j]=='x'and string[j+1]=='y'):
                count_xy +=1
                j+=2
            elif(string[j]=='y'and string[j+1]=='x'):
                count_yx +=1
                j+=2
            else:
                j=j+1
                pass
            
            
    total = count_yx+count_xy
    print(total)