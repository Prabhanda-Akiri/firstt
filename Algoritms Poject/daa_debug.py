import math

""" class containing all the functions required for Fleury's Algorithm"""
class Fleurys:

	#constructor to initialise the values of the graph
	def __init__(self,n,e,E):

		self.n=n
		self.e=e
		self.V=[]
		self.visited=[]

		self.init_vertices(E)

	""" this function is used to make the nodes for each of vertices in the graph 
	and store the required iformation"""
	def init_vertices(self,E):

		#creating nodes for vertices
		for i in range(self.n):
			temp=Vertex_Node(i)
			self.V.append(temp)

		#constructing the adjacency list for vertices by information from edge list
		for i in range(self.e):

			a=E[i][0]
			b=E[i][1]

			from_v=self.V[a]
			to_v=self.V[b]

			from_v.adj.append(to_v)
			to_v.adj.append(from_v)

	
	#Checks if the given graph can have a Eulerian Circuit/ Path
	def isEulerian(self):

		odd_count=0

		for i in range(self.n):
			no_adj_v=len(self.V[i].adj)

			if no_adj_v%2 == 1 :
				odd_count+=1

		"""for a graph to contain Eulerian Circuit/Path it should have 
		either 0 or 2 no.of vertices with odd degree"""

		if odd_count==0 or odd_count==2:
			return True

		return False

	def addEdge(self,a,b):
		
		from_v=self.V[a]
		to_v=self.V[b]

		from_v.adj.append(to_v)
		to_v.adj.append(from_v)

	def deleteEdge(self,u,v):

		length=len(self.V[u].adj)

		for i in range(length):
			adj_v=self.V[u].adj[i].value
			if adj_v==v:
				self.V[u].adj.pop(i)
				break

		length=len(self.V[v].adj)

		for i in range(length):
			adj_v=self.V[v].adj[i].value
			if adj_v==u:
				self.V[v].adj.pop(i)
				break

		return

	def Reachable(self,u):
		
		count=1
		self.visited[u]=True 

		no_adj=len(self.V[u].adj)

		for i in range(no_adj):

			adj=self.V[u].adj[i].value

			if self.visited[adj]==False:
				count=count+self.Reachable(adj)

		return count

	def isNextEdge(self,u,v):

		no_adj=len(self.V[u].adj)

		if no_adj==1:
			#print('hi, 1,',u)
			return True

		else:
			#print('hi, 2,',u)

			self.visited=[False for i in range(self.n)]
			count1=self.Reachable(u)

			self.deleteEdge(u,v)

			self.visited=[False for i in range(self.n)]
			count2=self.Reachable(u)

			self.addEdge(u,v)

			if count1==count2:
				return True 

			return False


	def giveRoute(self):
		
		u=0
		for  i in range(self.n):

			length=len(self.V[i].adj)
			#print(length)
			if length%2 !=0:
				u=i 
				break

		self.route=[]

		return self.storeRoute(u)

	def storeRoute(self,u):

		self.route.append(u)

		for v in self.V[u].adj:

			adj=v.value
			if self.isNextEdge(u,adj) :
				self.deleteEdge(u,adj)
				self.storeRoute(adj)

		return self.route

class Manhattan_Touring:

	def __init__(self,n,e,E):
		
		self.n=n 
		self.e=e 

		self.r=int(math.sqrt(self.n))
		self.init_edgetable(E)

		self.S=[[0 for i in range(self.r)] for i in range(self.r)]

	def init_edgetable(self,E):

		self.g_no=[[int(i/3),(i%3)] for i in range(self.n)]
		self.W_s=[[0 for i in range(self.r)] for i in range(self.r)] 
		self.W_e=[[0 for i in range(self.r)] for i in range(self.r)] 
		
		for i in range(len(E)):

			if E[i][0]+1==E[i][1] :

				from_v=E[i][0]
				s=self.g_no[from_v]

				self.W_e[s[0]][s[1]]=E[i][2]

			elif E[i][0]+self.r==E[i][1] :

				from_v=E[i][0]
				s=self.g_no[from_v]

				self.W_s[s[0]][s[1]]=E[i][2]

		print('Grid no\'s of vertices:		',self.g_no,'\nWeights of southern Roads:	',self.W_s,'\nWeights of eastern Roads:	',self.W_e,'\n')

	def longest_path(self):

		self.S[0][0]=0 
		#self.P=[0]
		#print(self.r)
		for i in range(1,self.r):
			#print(i,self.W_s[i][0])
			self.S[i][0]=self.S[i-1][0] + self.W_s[i-1][0]

		for j in range(1,self.r):
			self.S[0][j]=self.S[0][j-1] + self.W_e[0][j-1] 

		
		for i in range(1,self.r):
			for j in range(1,self.r):

				
				a=max((self.S[i-1][j]+self.W_s[i-1][j]),(self.S[i][j-1]+self.W_e[i][j-1]))

				"""if a==(self.S[i-1][j]+self.W_s[i-1][j]):
					#print(i-1,j,'	',i,j)
					if self.P[-1]!=int(self.r*(i-1)+j):
						self.P.append(int(self.r*(i-1)+j))
				else:
					#print(i,j-1,'	',i,j)
					self.P.append(int(self.r*(i)+j-1))"""

				self.S[i][j]=a 

		#self.P.append(self.n-1)
		return self.S[i][j]

	def give_path(self):

		self.P=[self.n-1]

		""""for i in range(self.r-1,0,-1):
			for j in range(self.r-1,0,-1):"""
		i=self.r-1
		j=self.r-1

		while( i!=0 and j!=0) :

			if self.S[i][j]==self.S[i-1][j]+self.W_s[i-1][j]:
				self.P.append(int(self.r*(i-1)+j))
				i-=1
			else:
				self.P.append(int(self.r*(i)+j-1))
				j-=1

		self.P.append(0)
		self.P.reverse()
		print(self.P)


class Vertex_Node:

	def __init__(self,v):
		self.value=v 
		self.adj=[]

class Edge_Node:

	def __init__(self,s,e,w):
		self.start=s 
		self.end=e 
		self.weight=w 

class algos_Interface:

	def __init__(self):
		pass 

def main():

	n=9
	e=9
	E=[[0,1,2],[0,3,1],[1,4,5],[1,2,1],[3,6,3],[3,4,3],[4,5,2],[4,7,4],[2,5,2],[5,8,1],[6,7,2],[7,8,6]]

	user_names=['Arjun','Karan','Sneha','Swathi']
	passwords=['arjun1','karan2','sneha3','swathi4']


	cities=[""]
	fl=Fleurys(n,e,E)

	print('\nisEulerian?	',fl.isEulerian())
	print('\n',fl.giveRoute())

	m=Manhattan_Touring(n,e,E)

	print('The maximun weight of route:	',m.longest_path())
	m.give_path()

	print('\n\nWelcome to the Spice Star travel guide\n\nWe are delighted to provide our service to you..!!\n')
	
	print('\nTo proceed further you must Login....\n')	
	print('\nNot a member yet ? press \'1\' to Sign Up\nAlready a member ? press \'2\' to Log In..')

	log_choice=0
	while log_choice<1 or log_choice>2 :
		
		log_choice=int(input())
		if log_choice==1 or log_choice==2:
			print("\nEnter a valid choice")
		else:
			break
	if log_choice==1:
		new_name=input('\nEnter your User-name:	')
		new_pass=input('\nEnter your Password:	')
		user_names.append(new_name)
		passwords.append(new_pass)
		print('\nNow you are Registered into Spice Stars services..\nYou can proceed to Login\n')
		log_choice=2

	if log_choice==2:
		
		u_name=input('\nEnter your User-name:	')
		u_pass=input('\nEnter your Password:	')
		uid=-1
		for i in user_names:
			if i==u_name :
				uid=i 
				break
		if passwords[uid]==u_pass :
			print('\nYou are successfully logged in.. !!!\n')
			print('\nHere are the list of Cities foor which we extend our services..\nChoose one among them\n')
			for i in cities :
				print('\n',i+1,'. ',cities[i])
			place=int(input())
			print('\nHere are the two kinds of services we\'ll be providing for the tourists based upon their requirements\n')
			#print('\nGo through them properly and make your choice..!!\n')
			print('1.	This service basically assumes you have enough fuel to travel all over the city.')
			print('We provide you a path to tour around the city such that you can visit all the places present',end='')
			print('in the city on existing roadways and also assure you that you don\'t visit a place twice.')
			print('Depending on the routes for the city the path given might take you to the same place')
			print('where you\'ve started initially or another place.')			
			print('2.	Manhattan Tour')


def select_file(a):
	if a==1:
		pass
	elif a==2:
		pass
	return abc.txt

if __name__ == '__main__':
	main()
