n, s = open(0)
for x in map(int, s.split()):
    print(min(15-i+-x % 2**i for i in range(16)))
