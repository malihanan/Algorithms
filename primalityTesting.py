import random

def gcd(x, y): 
   while(y): 
       x, y = y, x % y   
   return x 
   
def powerMod(x, y, p):
	res = 1
	x = x % p
	while(y > 0):
		if((y & 1) == 1):
			res = (res * x) % p
		y = y >> 1
		x = (x * x) % p
	return res

def isPrime(n):
	if (n <= 1 or n%2 == 0):
		return False
	for k in range(50):
		while True:
			a = random.randint(2, n-1)
			if gcd(a, n) == 1:
				break
		if powerMod(a, n-1, n) != 1:
			return False
	return True

if __name__ == '__main__':
	n = int(input("Enter number for testing: "))
	if isPrime(n):
		print("--> Number is prime.")
	else:
		print("--> Number is not prime.")
