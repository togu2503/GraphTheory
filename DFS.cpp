#include <iostream>
#include <vector>
using namespace std;

class Graph {

private:
	vector<bool> visited;
	vector<vector<int>> adj;
	int n;

public:
	Graph(int nodes);
	void AddEdge(int v, int w);
	void DFS(int v);
};

Graph::Graph(int nodes)
{
	n = nodes;
	visited = vector<bool>(n, false);
	adj = vector<vector<int>>(n, vector<int>(n, 0));
}

void Graph::AddEdge(int i, int j)
{
	adj[i][j] = 1;
	adj[j][i] = 1;
}

void Graph::DFS(int v)
{

	visited[v] = true;
	cout << v << " ";

	for (int i = 0; i < n; i++)
		if (adj[v][i] && !visited[i])
			DFS(i);
}

int main()
{
	Graph g(9);
	g.AddEdge(0, 6);
	g.AddEdge(1, 2);
	g.AddEdge(1, 7);
	g.AddEdge(2, 7);
	g.AddEdge(2, 6);
	g.AddEdge(3, 4);
	g.AddEdge(3, 5);
	g.AddEdge(3, 8);
	g.AddEdge(4, 5);
	g.AddEdge(5, 6);
	g.AddEdge(6, 7);

	std::cout<<"DFS from node 0\n";
	g.DFS(0);

	return 0;
}