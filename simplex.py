matrix = []
e = 2
def findPositiveMax(a):
	isPositive = False
	maxI = 2
	for i in range(2, len(a)-2):
		if a[i] > 0 and a[i] >= a[maxI]:
			isPositive = True
			maxI = i
	if isPositive:
		return maxI
	else:
		return -1
		
def simplex():
	l = 8
	cf = [0, 0, 10, 9, 0, 0, 0, 0]
	r = []
	r.append([0, 3, 3, 3, 1, 0, 21, 0])
	r.append([0, 4, 4, 3, 0, 1, 24, 0])
	
	while(True):
		dot = [0, 0]
		for i in range(2, l-1):
			val = 0
			for j in range(e):
				val += r[j][0] * r[j][i]
			dot.append(cf[i] - val)
		dot.append(0)
		print("-------------------------------")
		print("dot: ", end="")
		print(dot)
		maxI = findPositiveMax(dot)
		if maxI == -1:
			return -dot[l-2]
		print("MaxI: " + str(maxI) + "  Max: " + str(dot[maxI]))
		
		minJ = 0
		isPositive = False
		for i in range(e):
			r[i][l-1] = r[i][l-2] / r[i][maxI]
			if r[i][l-1] > 0 and r[i][l-1] <= r[minJ][l-1]:
				isPositive = True
				minJ = i
		if not isPositive:
			return -dot[l-2]
		print("Minj: " + str(minJ) + " Min: " + str(r[minJ][l-1]))
	
		pivot = r[minJ][maxI]
		print("Pivot: " + str(pivot))
		for i in range(2, l-1):
			r[minJ][i] = r[minJ][i] / float(pivot)
	
		for i in range(e):
			if i != minJ:
				x = r[i][maxI]
				for j in range(2, l-1):
					r[i][j] = r[i][j] - (x * r[minJ][j])
		r[minJ][0] = cf[maxI]
		r[minJ][1] = maxI - 1
			
		for i in range(e):
			print(r[i])
		print(dot)
		print("--------------------------------------")	
			
if __name__ == '__main__':
	print("--> Maximum: " + str(simplex()))
