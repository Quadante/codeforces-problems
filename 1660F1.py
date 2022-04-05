for t in range(int(input())):
    n = int(input())
    a = input()   
    s = 0
    for l in range(n):
        p,m=0,0
        for r in range(l, n):
            p+=(a[r]=='+')
            m+=(a[r]=='-')
            s+=((m-p)%3==0 and m>=p)
    print(s)