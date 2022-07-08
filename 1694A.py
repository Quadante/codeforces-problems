for _ in range(int(input())):
  t,c=map(int,input().split())
  print("01"*min(t,c)+"0"*max(0,t-c)+"1"*max(0,c-t))