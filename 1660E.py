for ii in range(int(input())):
    x = input()
    n = int(input())
    mat = []
    ans = 0
    for jj in range(n):
        x = input()
        t = []
        for kk in range(n):
            y = ord(x[kk])-ord("0")
            t.append(y)
            ans += y
        mat.append(t)
    i = 0
    for jj in range(n):
        temp = 0
        for kk in range(n):
            temp += mat[kk][(kk+jj) % n]
        i = max(temp, i)
    ans += n-2*i
    print(ans)
