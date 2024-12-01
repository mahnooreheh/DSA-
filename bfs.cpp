#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//bfs for undirected graphs
void addEdge(vector<vector<int>>& adj, int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u); 
}
void bfs(vector<vector<int>>& adj, int u) {
	vector<bool>visited(adj.size(), false);
	visited[u] = true; 
	queue<int> q1;
	q1.push(u); 
	while (!q1.empty()) {
		int frontt = q1.front(); 
		q1.pop();
		cout << frontt << " ";
		for (int j : adj[frontt]) {
			if (!visited[j]) {
				visited[j] = true; 
				q1.push(j); 
			}
		}
	}
}
int main() {
	// Number of vertices in the graph
	int V = 5;

	// Adjacency list representation of the graph
	vector<vector<int>> adj(V);

	// Add edges to the graph
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 4);

	// Perform BFS traversal starting from vertex 0
	cout << "BFS starting from 1: \n";
	bfs(adj, 1);

	return 0;
}