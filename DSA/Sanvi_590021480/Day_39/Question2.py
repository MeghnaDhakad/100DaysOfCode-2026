n=int(input("Enter the number of meetings: "))
intervals=[]
for i in range(n):
  start,end=map(int,input("Enter start and end time: ").split())
  intervals.append([start,end])

start=sorted(i[0] for i in intervals)
end=sorted(i[1] for i in intervals)
s=e=0
rooms=ans=0

while s<len(intervals):
  if start[s]<end[e]:
    rooms+=1
    ans=max(ans,rooms)
    s+=1
  else:
    rooms-=1
    e+=1
print(ans)
