for _ in [0]*int(input()):
	n = int(input())
	arr = list(map(int,input().split()))
	mn = min(arr)
	pos = arr.index(mn)
	print(n-1)
	for i in range(n):
		if i!=pos:
			print(i+1,pos+1,mn+abs(i-pos),mn)
 