class Node:
	def __init__(self, d):
		self.data = d
		self.next = None

class LinkedList:

	def __init__(self):
		self.head = None

	def setHead(self, n):
		self.head = n

	def print_list(self):
		temp = self.head
		while temp.next!=None:
			print(temp.data, end=" ")
			temp = temp.next
		print(temp.data)

	def getLast(self):
		temp = self.head
		if temp!=None:
			while temp.next!=None:
				temp = temp.next
		return temp

	def getMiddle(self):
		if self.head is None:
			return
		if self.head.next is None:
			return self.head.data

		slow = self.head
		fast = self.head
		while  fast.next != None and fast.next.next != None:
			slow = slow.next
			fast = fast.next.next
		return slow.data

	def extend(self, arr):
		l = self.getLast()
		for i in arr:
			n = Node(i)
			if l is None:
				self.head = n
			else:
				l.next = n
			l = n

	def insert(self, d, i):
		n=Node(d)
		if i==0:
			n.next=self.head
			self.head = n
		elif i==-1:
			l = self.getLast()
			if l is None:
				self.head = n
			else:
				l.next = n
		else:
			temp = self.head
			if temp is None:
				self.head = n
			else:
				for j in range(i-1):
					if temp.next==None:
						self.insert(d, -1)
						return
					temp=temp.next
				temp.next, n.next = n, temp.next

	def delete(self, d):
		temp = self.head
		if temp.data == d:
			temp = self.head.next
			del self.head
			self.head = temp
			return
		while temp.next.next!=None:
			if temp.next.data==d:
				t = temp.next.next
				del temp.next
				temp.next = t
				return
			temp = temp.next
		if temp.next.data == d:
			del temp.next
			temp.next=None

	def get(self, a):
		temp = self.head
		if temp==None:
			return
		while temp.next!=None:
			if temp.data == a:
				return temp
			temp = temp.next
		if temp.data==a:
			return temp

	def set_next(self, a, b):
		ptr_a = self.get(a)
		ptr_b = self.get(b)
		ptr_a.next = ptr_b

	def is_loop(self):
		ans, meet_node = self.is_loop_util()
		return ans

	def is_loop_util(self):
		if self.head is None or self.head.next is None:
			return False, None
		if self.head.next == self.head:
			return True, self.head
		slow = self.head
		fast = self.head
		while fast.next!=None and fast.next.next!=None:
			slow = slow.next
			fast = fast.next.next
			if fast == slow:
				return True, fast
		else:
			return False, None

	def remove_loop(self):
		ans, meet_node = self.is_loop_util()
		if ans:
			slow = self.head
			fast = meet_node
			prev = fast
			while fast!=slow:
				prev = fast
				fast = fast.next
				slow = slow.next
			prev.next = None

	def reverse(self):
		if self.head==None or self.head.next==None:
			return
		prev = self.head
		curr = self.head.next
		prev.next = None
		if curr.next==None:
			self.head=curr
		while curr.next != None:
			self.head = curr.next
			curr.next = prev
			prev = curr
			curr = self.head
		self.head.next = prev

	def is_palindrome(self):
		LinkedList.t = self.head
		if self.head is None or self.head.next is None:
			return True
		else:
			ans, t = self.is_palindrome_util(self.head)
			return ans

	def is_palindrome_util(self, curr):
		if curr.next is not None:
			prev, t = self.is_palindrome_util(curr.next)
		else:
			prev, t = True, self.head
		ans = curr.data == t.data and prev
		return ans, t.next

	def swap(self, a, b):
		if self.head is None or self.head.next is None or a==b:
			return

		#initialize pointers
		prev_a = prev_b = self.head
		ptr_a = ptr_b = self.head.next

		#is a or b is at first position
		if a == self.head.data:
			prev_a = None
			ptr_a = self.head
		if b == self.head.data:
			prev_b = None
			ptr_b = self.head

		#find position of a,b and their parents
		while ptr_a.next is not None and ptr_b.next is not None and (ptr_a.data != a or ptr_b.data != b):
			if ptr_a.data != a:
				ptr_a = ptr_a.next
				prev_a = prev_a.next
			if ptr_b.data != b:
				ptr_b = ptr_b.next
				prev_b = prev_b.next

		#if a or b is not found, return
		if ptr_a.data != a or ptr_b.data != b:
			return

		#check if a or b is head and set pointers accordingly
		if prev_a == None:
			self.head = ptr_b
		else:
			#this will set b->b if b,a are consecutive. It is taken care of later.
			prev_a.next = ptr_b
		if prev_b == None:
			self.head = ptr_a
		else:
			prev_b.next = ptr_a

		#if a,b are consecutive, prev of 1 will be same as the other. 
		if prev_b == ptr_a:
			ptr_b.next, ptr_a.next = ptr_a, ptr_b.next
		elif prev_a == ptr_b:
			ptr_b.next, ptr_a.next = ptr_a.next, ptr_b
		else:
			ptr_b.next, ptr_a.next = ptr_a.next, ptr_b.next

if __name__ == '__main__':
	l = LinkedList()
	l.extend([10, 15, 12, 13, 20, 14])
	l.set_next(14, 20)
	print(l.is_loop())
	l.remove_loop()
	l.print_list()