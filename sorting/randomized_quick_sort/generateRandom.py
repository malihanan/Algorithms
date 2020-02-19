#linear congruation generator
def generateRandom(x0):
	ran = []
	n = pow(2, 31) - 1
	a = pow(7, 5) # [or] a = pow(7, 13)
	b = 0
	for i in range(10):
		x0 = a * x0 + b
		ran.append(x0 % n)
	return ran

if __name__ == '__main__':
	x0 = int(input("seed: "))
	ran = generateRandom(x0)
	print(ran)
