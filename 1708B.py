for _ in range(int(input())):
  n,l,r=map(int,input().split())
  li=[]
  bo='YES'
  for i in range(1,n+1):
    if(((l-1)//i+1)*i>r):bo='NO';break
    li.append(((l-1)//i+1)*i)
  print(bo)
  if(bo=='YES'):print(*li)