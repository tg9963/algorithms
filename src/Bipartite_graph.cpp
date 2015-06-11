#include<iostream>
#include<list>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	
	public:
		graph(int v)
		{
			this->v=v;
			adj=new list<int>[v];
		}
		void add_edge(int start,int end)
		{
			adj[start].push_back(end);
		} 
		int bfs(int init)
		{
			bool *visited=new bool[v];
			int *color=new int[v];
			for(int i=0;i<v;i++)
			{
				visited[i]=false;
				color[i]=-1;
			}
			list<int> queue;
			queue.push_back(0);
			visited[init]=true;
			color[init]=1;
			int temp=0;
			while(!queue.empty())
			{
				temp=queue.front();
				queue.pop_front();
		 		list<int>::iterator i;
				for(i=adj[temp].begin();i!=adj[temp].end();++i)
				{
					if(visited[*i]==false)
					{
						visited[*i]=true;
						color[*i]=1-color[temp];
						queue.push_back(*i);
					}
					else
					{
						if(color[*i]==color[temp])return 0;
					}
				}
			}
			return 1;
		}
};

int main()
{
	
	  graph g(4); 
	  g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
	 if(g.bfs(0))
	 {
	 	cout<<"Bipartite ";
	 }
	 else
	 {
	 	cout<<"Not Bipartite";
	 } 	

	return 0;
}
