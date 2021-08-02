def minus(AVG, a):
    count = 0
    summ = 0
    final = []
    while AVG < a[-1]:
        summ += a[-1]
        a.pop(-1)
        count += 1
    final.append(count)
    final.append(summ)
    final.append(a)
    return final
 
 
t = int(input())
for times in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    max_summ = 0
    count = 0
    a.sort()
    for i in range(n):
        max_summ += a[i]
    AVG = max_summ // n
    while AVG < a[-1]:
        x = minus(AVG, a)
        n -= x[0]
        max_summ -= x[1]
        a = x[2]
        AVG = max_summ // n
        count += x[0]
    print(count)