def stringMatch(text, pattern):
	n = len(text)
	m = len(pattern)
	for s in range(n-m+1):
		for t in range(m):
			if(text[s+t]!=pattern[t]):
				break
		else:
			print("Match found at " + str(s))

text = input("Text: ")
pattern = input("Pattern: ")
stringMatch(text, pattern)
