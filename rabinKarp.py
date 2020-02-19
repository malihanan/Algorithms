d=10

def stringMatch(text, pattern):
	n = len(text)
	m = len(pattern)
	q = 13
	h = pow(d,m-1)%q
	p = t = 0
	for i in range(m):
		p = (d*p+int(pattern[i]))%q
		t = (d*t+int(text[i]))%q
	for s in range(n-m+1):
		if(p == t):
			for i in range(m):
				if(text[s+i]!=pattern[i]):
					break
			else:
				print("Match found at " + str(s))
		if(s < n-m):
			t = (((t-int(text[s])*h)*d)+int(text[s+m]))%q

if __name__ == '__main__':
	text = input("Text: ")
	pattern = input("Pattern: ")
	stringMatch(text, pattern)
