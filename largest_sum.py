#largest sum contiguous subarray

def largest_sum(arr):
	curr_sum = max_sum = 0
	for i in arr:
		curr_sum += i
		if curr_sum <= 0:
			curr_sum = 0
		else:
			max_sum = max(max_sum, curr_sum)
	return max_sum

if __name__ == '__main__':
	arr = [-2, -3, 4, -1, -2, 1, 5, -3]
	print(largest_sum(arr))