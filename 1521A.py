I = lambda: int(input())
tup = lambda: map(int, input().split())
lst = lambda: list(map(int, input().split()))
 
 
def solve():
    a,b=tup()
    if b==1:
        print("NO")
    else:
        print("YES")
        print(a*b,a,(b+1)*a)
 
 
#t = 1
t = I()
while t:
    solve()
    t -= 1