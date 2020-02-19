import math

class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def __str__(self):
		return "[" + str(self.x) + ", " + str(self.y) + "]"
	def __repr__(self):
		return str(self)

def grahamScan(points):
	o = selectOrigin(points)
	angles = findAngles(points, o)
	filterSamePolarAngles(angles, points)
	points = [points for angles, points in sorted(zip(angles,points))] #sorting points based on angles
	s = []
	s.append(points[0])
	s.append(points[1])
	s.append(points[2])
	for i in range(3, len(points)):
		while(direction(s[-2], s[-1], points[i]) >= 0 ):
			s.pop()
		s.append(points[i])
	return s
	
def direction(p1, p2, p3):
	return ((p3.x - p1.x) * (p2.y - p1.y)) - ((p2.x - p1.x) * (p3.y - p1.y))

def selectOrigin(points):
	o = point(999, 999)
	for p in points:
		if p.y < o.y or (p.y == o.y and p.x < o.x):
			o = p
	return o

def filterSamePolarAngles(angles, points):
	i = 0
	while i < len(angles)-1:
		j = i+1
		while j < len(angles):
			if angles[i] == angles[j]:
				if points[i].y < points[j].y:
					angles.pop(i)
					points.pop(i)
				else:
					angles.pop(j)
					points.pop(j)
				j-=1
			j+=1
		i+=1

def findAngles(points, origin):
	angles = []
	for i in range(len(points)):
		if points[i].x != 0:
			angles.append(math.atan(((float)(points[i].y - origin.y)) / (points[i].x - origin.x)))
		else:
			if points[i].y == 0:
				angles.append(0)
			else:
				angles.append(math.pi)
	return angles

if __name__ == '__main__':
	points = [point(3, 1), point(0, 0), point(0, 3), point(1, 1), point(2, 2), point(3, 3), point(4, 4), point(1, 2)]
	s = grahamScan(points)
	print(s)

