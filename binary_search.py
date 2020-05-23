def search(arr, key, l, h):
	if h < l:
		return -1
	mid = ((h-l) // 2) + l
	if arr[mid] == key:
		return mid
	elif arr[mid] < key:
		return search(arr, key, mid+1, h)
	else:
		return search(arr, key, l, mid-1)

if __name__ == '__main__':
	arr = [7, 3, 22, 65, 3, 23, 90, 45, 23, 46, 65]
	arr.sort()
	print("Array:", arr)
	key = 900
	print("index of", key, ":", search(arr, key, 0, len(arr)-1))