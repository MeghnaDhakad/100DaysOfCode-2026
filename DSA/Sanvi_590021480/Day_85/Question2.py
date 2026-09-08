n=int(input("Enter n: "))
start=list(map(int,input("Enter start: ").split()))
end=list(map(int,input("Enter end: ").split()))
activities=list(zip(start,end))
activities.sort(key=lambda x:x[1])
count=0
lastend=0
for s,e in activities:
    if s>=lastend:
        count+=1
        lastend=e

print(count)
