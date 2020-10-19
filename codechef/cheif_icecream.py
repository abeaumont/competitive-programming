for _ in range(int(input())):
    people = int(input())
    values = list(map(int,input().split()))
    money = 0
    flag = 1

    for i in values:
        if(i==5):
            money = money + 5
        else:
            change = i - 5
            if(money-change>=0):
                money = money - change
            else:
                flag = 0
                
    if(flag):
        print('YES')
    else:
        print('NO')