import collections
for _ in range(int(input())):
    n = int(input())
    l = 2*n+2
    s = input().strip()
    y = [[0]*(l+1) for i in range(3)]
    def upd(x, a):
        while x <= l: a[x]+=1; x += x&(-x)
    def qry(x, a):
        r = 0
        while x > 0: r+=a[x]; x -= x&(-x)
        return r
    ans = 0; t = n+1; upd(t, y[t%3])
    for i in s:
        t = t+(1 if i == '-' else -1)
        ans += qry(t, y[t%3]); upd(t, y[t%3])
    print(ans)