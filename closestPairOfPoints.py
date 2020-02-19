import math

class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y

def closestPairOfPoints(points):
	d = math.inf
	for i in range(len(points)):
		for j in range(len(points)):
			if i != j:
				t = math.sqrt(((points[i].x-points[j].x)**2) + ((points[i].y-points[j].y)**2))
				if t < d:
					d = t
					i_min = i
					j_min = j
	return points[i_min], points[j_min]

if __name__ == '__main__':
	points = [point(1, 1), point(2, -4), point(-1, -6), point(7, 2), point(2, -1)]
	i, j = closestPairOfPoints(points)
	print("[" + str(i.x) + ", " + str(i.y) + "] & [" + str(j.x) + ", " + str(j.y) + "]")