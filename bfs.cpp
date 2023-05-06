
#include <bits/stdc++.h>
using namespace std;


class Graph {
	int V; 
	vector<vector<int> > adj;

public:
	Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
	void addEdge(int v, int w)
      {
		   adj[v].push_back(w); 
	  }

	
	void BFS(int s)
    {
        bool visited[V];
        queue<int>q;
  		q.push(s);
  		visited[s]=true;
  		while(!q.empty())
		{
		    int u=q.front();
		    cout<<u<<" ";
		    q.pop();
		    for(int i=0;i<adj[u].size();i++)
			{
		      if(!visited[adj[u][i]])
			  {
		        q.push(adj[u][i]);
		        visited[adj[u][i]]=true;
		      }
	    	}
  		}
	}


};

int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 

	return 0;
}

