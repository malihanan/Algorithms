#reduction of sumOfSubset to 0/1 Knapsack
def knapsack(p, w, c):
	t=[]
	for i in range(len(p)+1):
		row=[0]*(c+1)
		t.append(row)
		
	for i in range(1,len(p)+1):
		for j in range(1,c+1):
			if(w[i-1]>j):
				t[i][j]=t[i-1][j]
			else:
				if(t[i-1][j-w[i-1]]+p[i-1] > t[i-1][j]):
					t[i][j]=t[i-1][j-w[i-1]]+p[i-1]
				else:
					t[i][j]=t[i-1][j]
	print()
	print('\n'.join([''.join(['{:3}'.format(item) for item in row])for row in t]))
	print()
	ans=[0]*len(w)
	i=len(p)
	j=c
	for i in range(len(p), 0, -1):
		if(t[i][j]!=t[i-1][j]):
			ans[i-1]=1
			j-=w[i-1]
	return ans
	
if __name__ == "__main__":
	w = list(map(int, input("Enter numbers: ").split()))
	c = int(input("Enter sum: "))
	p = w.copy()#[1]*len(w)
	print('w:', end=" ")
	print(w)
	print('p:', end=" ")
	print(p)
	ans=knapsack(p, w, c)
	print("selecteditems:", end=" ")
	for i in range(len(ans)):
		if ans[i]==1:
			print(str(w[i]), end=" ")
