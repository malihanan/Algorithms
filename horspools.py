N=26	#no. of alphabets

def horspools(text, pattern):
	text = text.upper()
	pattern = pattern.upper()
	n = len(text)
	m = len(pattern)
	t = [m]*(N+1)
	for i in range(m-1):
		t[index(pattern[i])] = m-1-i
	i = m-1
	while i<n:
		k=0
		while k<m and pattern[m-1-k] == text[i-k]:
			k+=1
		if k == m:
			print("match found at " + str(i-m+1))
			i = i+m
		else:
			i = i + t[index(text[i])]
	
def index(c):
	if(c>='A' and c<='Z'):
		return (ord(c)-ord('A'))
	else:
		return N
		
if __name__ == '__main__':
	text = input("Text: ")
	pattern = input("Pattern: ")
	horspools(text, pattern)
