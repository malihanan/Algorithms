'''
We have an array arr[0 . . . n-1]. We should be able to
1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1
2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.

Time Complexity: Tree Creation - O(n), Updation/Getting Sum - O(log n)
Space Complexity: O(n)
'''

import math

class SegmentTree:
	def __init__(self, arr):
		self.arr = arr
		self.n = len(arr)
		self.st = [0] * (2 * 2**(math.ceil(math.log2(self.n))) - 1)
		self.construct(arr, 0, self.n-1, 0)

	def construct(self, arr, ss, se, si):
		if ss==se:
			self.st[si] = arr[ss]
			return arr[ss]
		mid = ss + (se - ss) // 2
		self.st[si] = self.construct(arr, ss, mid, 2*si+1) + self.construct(arr, mid+1, se, 2*si+2)
		return self.st[si]

	def getSum(self, l, r):
		if l<0 or l>r or r>=self.n:
			return -1
		return self.getSumUtil(l, r, 0, self.n-1, 0)

	def getSumUtil(self, l, r, ss, se, si):
		if l<=ss and r>=se:
			return self.st[si]
		if l>se or r<ss:
			return 0
		mid = ss + (se - ss) // 2
		return self.getSumUtil(l, r, ss, mid, 2*si+1) + self.getSumUtil(l, r, mid+1, se, 2*si+2)

	def updateValue(self, i, val):
		if i<0 or i>=self.n:
			return
		diff = val - self.arr[i]
		self.arr[i] = val
		self.updateValueUtil(0, self.n-1, i, diff, 0)

	def updateValueUtil(self, ss, se, i, diff, si):
		if i<ss or i>se:
			return
		self.st[si] += diff
		if ss!=se:
			mid = ss + (se-ss)//2
			self.updateValueUtil(ss, mid, i, diff, 2*si+1)
			self.updateValueUtil(mid+1, se, i, diff, 2*si+2)

if __name__ == '__main__':
	arr = [1, 3, 5, 7, 9, 11]
	st = SegmentTree(arr)
	print(st.getSum(3,5))
	st.updateValue(2,4)
	print(st.getSum(0,3))