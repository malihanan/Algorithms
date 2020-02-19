class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y

def lineSegmentIntersection(P1, P2, P3, P4):
	d1 = direction(P3, P4, P1)
	d2 = direction(P3, P4, P2)
	d3 = direction(P1, P2, P3)
	d4 = direction(P1, P2, P4)
	if ((d1>0 and d2<0) or (d1<0 and d2>0)) and ((d3>0 and d4<0) or (d3<0 and d4>0)):
		return True
	if d1==0 and onSegment(P3, P4, P1):
		return True
	if d2==0 and onSegment(P3, P4, P2):
		return True
	if d3==0 and onSegment(P1, P2, P3):
		return True
	if d4==0 and onSegment(P1, P2, P4):
		return True
	return False

def direction(P1, P2, P3):
	return ((P3.x - P1.x) * (P2.y - P1.y)) - ((P2.x - P1.x) * (P3.y - P1.y))

def onSegment(P1, P2, P3):
	if (min(P1.x, P2.x) <= P3.x <= max(P1.x, P2.x)) and (min(P1.y, P2.y) <= P3.y <= max(P1.y, P2.y)):
		return True
	return False

if __name__ == '__main__':
	if lineSegmentIntersection(point(1, 1), point(-2, 5), point(4,6), point(-3, 2)):
		print("Intersects")
	else:
		print("Doesn't Intersect")