#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph {
private:
	map<int, bool> visited;
	map<int, list<int>> adj;
public:
	void AddEdge(int v, int w);

	void DFS(int v);
};

void Graph::AddEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	for (const auto& i : adj[v])
		if (!visited[i])
			DFS(i);
}

int main()
{
	Graph g;
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

	cout << "DFS (starting from vertex 0) \n";

	g.DFS(0);

	return 0;
}