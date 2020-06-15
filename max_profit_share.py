#Maximum profit by buying and selling a share at most twice
import math

def max_profit_2_transactions(price):
	n = len(price)
	profit = [0]*n
	
	#find maximum profit off 1 transaction -> subtract from maximum price your current price
	max_price = price[-1]
	for i in range(n-2, -1, -1):
		if price[i] > max_price:
			max_price = price[i]
		profit[i] = max(profit[i+1], max_price - price[i])
	#profit[0] will have the maximum profit off 1 transaction
	#proft[i] will have maximum profit off 1 transaction for price[i..n-1]

	min_price = price[0]
	#find maximum profit off 2 transactions
	for i in range(1, n):
		if price[i]<min_price:
			min_price = price[i]
		profit[i] = max(profit[i-1], profit[i] + price[i]-min_price)
	#profit[i] will have maximum profit of 1 transaction and profit of 2 transactions for price[0..i]
	return profit[-1]

def max_profit_k_transactions(price, k):
	n = len(price)
	profit = [[0 for i in range(n)] for j in range(k+1)]

	for i in range(1, k+1):
		prevDiff = -math.inf
		for j in range(1, n):
			prevDiff = max(prevDiff, profit[i-1][j-1] - price[j-1])
			profit[i][j] = max(profit[i][j-1], price[j] + prevDiff)

	return profit[k][n-1]

if __name__ == '__main__':
	arr = [2, 30, 15, 10, 8, 25, 80]
	print(max_profit_2_transactions(arr))
	print(max_profit_k_transactions(arr, 2))
	arr = [12, 14, 17, 10, 14, 13, 12, 15]
	print(max_profit_k_transactions(arr, 3))