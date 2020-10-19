for _ in range(int(input())):
    ts = int(input())
    # ct_odd = (ts-1)//2

    # if(ts%2!=0 or 1%2!=0):
    #     ct_odd += 1

    # ct_even = (ts-1+1)-ct_odd

    # #print(ct_odd)
    # print(ct_even)
    while(ts%2==0):
        ts = int(ts / 2)

    print(int(ts/2))