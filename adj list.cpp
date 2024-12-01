#include<iostream>
#include<vector>
using namespace std;

//for directed graphs: 
void addedge(vector<vector<int>>& adj, int u, int v) {
	adj[u].push_back(v); 
}
void displayadjlist(vector<vector<int>>& adj) {
	for (int i = 0; i < adj.size(); i++) {
		cout << i << ": ";
		for (int j : adj[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
}

//for unirected graph
void addedge1(vector<vector<int>>& adj, int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u); 
}

//for weighted graphs

int main() {
	int V = 3;
	vector<vector<int>>adj(V);
	addedge1(adj, 0, 1);
	addedge1(adj, 0, 2);
	addedge1(adj, 1, 2);
	displayadjlist(adj);

}