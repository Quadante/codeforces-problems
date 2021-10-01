
    from bisect import bisect_left as bl
    import sys
    input=sys.stdin.readline
    n=int(input())
    a=sorted(map(int,input().split()))
    d=sum(a)
    m=int(input())
    for i in range(m):
      x,y=map(int,input().split())
      i=bl(a,x)
      j=bl(a,d-y)
      print(min(max(0,y-d+a[k])+max(0,x-a[k]) for k in (i,j)*(max(i,j)<n)+(i-1,j-1)))