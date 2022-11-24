import random as rd

range = 500
s = []
while (len(s) < range):
	n = rd.randint(0, range)
	if n not in s:
		s.append(n)

for i in s:
	print(i, end =" ")
print()
