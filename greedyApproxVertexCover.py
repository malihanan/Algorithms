import random

class edge:
	def __init__(self, u, v):
		self.u = u
		self.v = v
		
	def __repr__(self):
		return "({},{})".format(self.u, self.v)
		
def getDegree(G, v):
	d = 0
	for e in G['edges']:
		if e.u == v or e.v == v:
			d+=1
	return d
		
def greedyApproxVertexCover(G):
	degree = {}
	for v in G['vertices']:
		degree[v] = getDegree(G, v)
	degree = sorted(degree.items(), key = lambda x:(x[1], x[0]))
	print(degree)
	return 1

if __name__ == '__main__':
	G = {'vertices': [1,2,3,4,5], 'edges': [edge(1,2), edge(1,3), edge(2,4), edge(2,5), edge(3,4), edge(4,5)]}
	#G = {'vertices': [1,2,3,4,5,6], 'edges': [edge(1,4), edge(1,5), edge(1,6), edge(2,4), edge(2,5), edge(2,6), edge(3,4), edge(3,5), edge(3,6)]}
	print("\n+-------------------------------+\n|vertex cover of length {} found.|\n+-------------------------------+\n".format(greedyApproxVertexCover(G)))
