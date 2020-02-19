import random

class edge:
	def __init__(self, u, v):
		self.u = u
		self.v = v
		
	def __repr__(self):
		return "({},{})".format(self.u, self.v)
		
def approxVertexCover(G):
	edges = G['edges']
	c = set()
	n = len(edges)
	while (len(edges) != 0):
		e = edges[random.randrange(0,n,1)] 
		print("{} selected".format(e))
		c.add(e.u)
		c.add(e.v)
		print(c)
		i=0
		while (i<n):
			if edges[i].u == e.u or edges[i].u == e.v or edges[i].v == e.u or edges[i].v == e.v:
				print("removed {}".format(edges[i]))
				edges.remove(edges[i])
				i-=1
				n-=1
			i+=1
	return len(c)

if __name__ == '__main__':
	#G = {'vertices': [1,2,3,4,5], 'edges': [edge(1,2), edge(1,3), edge(2,4), edge(2,5), edge(3,4), edge(4,5)]}
	G = {'vertices': [1,2,3,4,5,6], 'edges': [edge(1,4), edge(1,5), edge(1,6), edge(2,4), edge(2,5), edge(2,6), edge(3,4), edge(3,5), edge(3,6)]}
	print("\n+-------------------------------+\n|vertex cover of length {} found.|\n+-------------------------------+\n".format(approxVertexCover(G)))
