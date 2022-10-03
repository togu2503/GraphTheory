#include <vector>
#include <queue>
#include <list>
#include <iostream>
using namespace std;

class Graph
{
	int n;
	vector<list<int>> adj;
public:
	Graph(int V);

	void AddEdge(int v, int w);

	void BFS(int s, int f);
};

Graph::Graph(int v)
{
	n = v;
	adj.resize(n);
}

void Graph::AddEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::BFS(int s, int f)
{
	int current = s;
	vector<bool> visited;
	visited.resize(n, false);
	vector<int> prev(n, -1);

	queue<int> queue;

	visited[current] = true;
	queue.push(s);

	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();

		for (auto adjecent : adj[current])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push(adjecent);
				if(prev[adjecent] == -1)
					prev[adjecent] = current;
			}
		}
	}

	if (visited[f])
	{
		current = f;

		while (current != s)
		{
			cout << current << " ";
			current = prev[current];
		}
		std::cout << s;
	}
	else
	{
		cout << "No way";
	}
}


int main()
{

	Graph g(9);
	g.AddEdge(0, 6);
	g.AddEdge(1, 2);
	g.AddEdge(1, 7);
	g.AddEdge(2, 6);
	g.AddEdge(2, 7);
	g.AddEdge(3, 4);
	g.AddEdge(3, 5);
	g.AddEdge(3, 8);
	g.AddEdge(4, 5);
	g.AddEdge(5, 6);
	g.AddEdge(6, 7);

	cout << "Path from 0 to 7\n";
	g.BFS(0, 7);

	return 0;
}