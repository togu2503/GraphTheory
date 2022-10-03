#include <iostream>
#include <map>
#include <list>
#include <stack>

using namespace std;

class Graph {
private:
	map<int, bool> visited;
	map<int, list<int>> adj;
	stack<int> path;
public:
	void AddEdge(int v, int w);

	void DFS(int start, int end);
};

void Graph::AddEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::DFS(int start, int end)
{
	if (adj.count(end) == 0)
		return;

	visited[start] = true;
	path.push(start);

	int current = start;

	while (!path.empty() && path.top() != end)
	{
		int next = -1;

		for (const auto& i : adj[current])
			if (!visited[i])
			{
				next = i;
				break;
			}

		if (next == -1)
		{
			current = path.top();
			path.pop();
		}
		else
		{
			visited[next] = true;
			current = next;
			path.push(current);
		}
	}

	if (path.top() == end)
	{
		while (!path.empty())
		{
			cout << path.top() << " ";
			path.pop();
		}
	}
	else
	{
		cout << "No way";
	}
}

int main()
{
	Graph g;
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

	cout << "DFS (starting from vertex 0 to vertex 7) \n";

	g.DFS(0, 7);

	return 0;
}