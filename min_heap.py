class MinHeap:

	def __init__(self, arr):
		self.size = len(arr)
		self.arr = arr
		i=(self.size-1)//2
		while i>=0:
			self.min_heapify(i)
			i-=1

	def min_heapify(self, i):
		l = (2*i)+1
		r = (2*i)+2

		smallest = i
		if l<self.size and self.arr[l]<self.arr[smallest]:
			smallest = l
		if r<self.size and self.arr[r]<self.arr[smallest]:
			smallest = r
		if smallest!=i:
			self.arr[i], self.arr[smallest] = self.arr[smallest], self.arr[i]
			self.min_heapify(smallest)

	def extract_min(self):
		ans = self.arr[0]
		self.arr[0] = self.arr[self.size-1]
		self.min_heapify(0)
		self.size -= 1
		return ans

	def get_min(self):
		return self.ans[0]

	def insert(self, k):
		self.size+=1
		self.arr.append(k)

		ik = self.size - 1
		ip = (ik - 1)//2
		while ik!=0 and self.arr[ip] > self.arr[ik]:
			self.arr[ip], self.arr[ik] = self.arr[ik], self.arr[ip]
			ik = ip
			ip = (ik-1)//2

if __name__ == '__main__':
	a = [7,3,6,2,5,9,4,6,1]
	print(a)
	m = MinHeap(a)
	m.insert(4)
	m.insert(0)
	print(a)
	for i in range(len(a)):
		print(m.extract_min(), end=" ")
