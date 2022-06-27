n = int(input())
m_1 = [input().strip()[::2], input().strip()[::2]]
m_2 = [input().strip()[::2], input().strip()[::2]]
 
top = 0
bot = 0
tot = 0
 
for i in range(n):
	top += (m_1[0][i] == "1") - (m_2[0][i] == "1")
	bot += (m_1[1][i] == "1") - (m_2[1][i] == "1")
 
	if top > 0 and bot < 0:
		tot += 1
		top -= 1
		bot += 1
 
	elif top < 0 and bot > 0:
		tot += 1
		top += 1
		bot -= 1
 
	tot += abs(top) + abs(bot)
 
if top+bot != 0:
	print(-1)
else:
	print(tot)