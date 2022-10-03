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

	void DFS(int v);
};

void Graph::AddEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::DFS(int start)
{
	visited[start] = true;
	path.push(start);
	cout << start << " ";

	int current = start;

	while (!path.empty())
	{
		int next = -1;

		for (const auto& i : adj[current])
			if (!visited[i])
			{
				next = i;
				break;
			}

		if(next == -1)
		{
			current = path.top();
			path.pop();
		}
		else
		{
			cout << next << " ";
			visited[next] = true;
			current = next;
			path.push(current);
		}
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

	cout << "DFS (starting from node 0) \n";

	g.DFS(0);

	return 0;
}