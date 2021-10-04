n, m = list(map(int, input().split()))
l = []
for _ in range(n):
    book = list(input())
    book[1::2]= map(lambda x : chr(155-ord(x) ), book[1::2])
    l.append(book)
 
print(*sorted(range(1, n+1), key = lambda x : l[x-1]))