#We are given an array and a set of query ranges, we are required to find the sum of every query range. Array is not static, values can update.
#Time Complexity: O(sqrt(n))

class QueryRange:
	def __init__(self, arr):
		self.arr = arr
		self.n = len(self.arr)
		self.block_size = int(self.n**(1/2))
		self.preprocess()

	def preprocess(self):
		self.block = []
		c = 0
		for i in range(self.n):
			if i%self.block_size == 0:
				self.block.append(0)
			self.block[-1] += self.arr[i]

	def query(self, l, r):
		ans = 0
		while l%self.block_size != 0 and l<r:
			ans+=arr[l]
			l+=1

		while l+self.block_size-1 <= r:
			ans+=self.block[l//self.block_size]
			l+=self.block_size

		while l<=r:
			ans+=self.arr[l]
			l+=1

		return ans

	def update(self, i, val):
		self.block[i//self.block_size] -= self.arr[i]
		self.arr[i] = val
		self.block[i//self.block_size] += self.arr[i]

if __name__ == '__main__':
	arr = [1, 5, 2, 4, 6, 1, 3, 5, 7, 10]
	q = QueryRange(arr)
	print("Sum for query(3,8):", q.query(3,8))
	print("Sum for query(1,6):", q.query(1,6))
	q.update(8, 0)
	print("Sum for query(8,8):", q.query(8,8))