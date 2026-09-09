coins=list(map(int,input("Enter denominations: ").split()))
amount=int(input("Enter amount: "))
coins.sort(reverse=True)
count=0
for i in coins:
    while amount>=i:
        amount-=i
        count+=1
if amount==0:
    print(count)
else:
    print(-1)
