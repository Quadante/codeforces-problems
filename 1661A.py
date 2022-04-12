for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    e = []
    for i in range(n-1):
        c = abs(a[i]-a[i+1])+abs(b[i]-b[i+1])
        d = abs(a[i]-b[i+1])+abs(b[i]-a[i+1])
        e.append(min(c, d))
    print(sum(e))
