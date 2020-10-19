for _ in range(int(input())):
    n, k = map(int, input().split())
    prices = list(map(int, input().split()))
    initial_rev = sum(prices)
    for i in range(len(prices)):
        if(prices[i]>k):
            prices[i] = k
    
    loss = initial_rev - sum(prices)
    print(loss)