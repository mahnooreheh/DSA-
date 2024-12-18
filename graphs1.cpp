#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include<vector>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    unordered_map<int, bool> visited;

    void bfs(int u) {
        queue<int> q1;
        q1.push(u);
        visited[u] = true;
        while (!q1.empty()) {
            int frontt = q1.front();
            q1.pop();
            cout << frontt << "->";
            for (auto j : adj[frontt]) {
                if (!visited[j]) {
                    visited[j] = true;
                    q1.push(j);
                }
            }
        }
    }

    unordered_map<int, bool> visited1;
    void dfs(int u) {
        visited1[u] = true;
        cout << u << "->";
        for (auto i : adj[u]) {
            if (!visited1[i]) {
                dfs(i);
            }
        }
    }

    unordered_map<int, int> parent;
    unordered_map<int, bool> visited2;

    bool detectCycle(int u) {
        queue<int> q1;
        q1.push(u);
        visited2[u] = true;
        while (!q1.empty()) {
            int frontt = q1.front();
            q1.pop();
            for (auto j : adj[frontt]) {
                if (!visited2[j]) {
                    parent[j] = frontt;
                    visited2[j] = true;
                    q1.push(j);
                }
                else if (parent[frontt] != j) { // If a node has two parents
                    return true;
                }
            }
        }
        return false;
    }

    unordered_map<int, bool> visited3;
    stack<int> s2;

    void dfstopsort(int u) {
        visited3[u] = true;
        for (auto j : adj[u]) {
            if (!visited3[j]) {
                dfstopsort(j);
            }
        }
        s2.push(u);
         
    }

    void printtopsort() {
        visited3.clear();
        for (auto i : adj) {
            if (!visited3[i.first]) {
                dfstopsort(i.first);
            }
        }

        cout << "Topological Sort: ";
        while (!s2.empty()) {
            cout << s2.top() << " ";
            s2.pop();
        }
        cout << endl;
    }
    unordered_map<int, int>parent1;
    unordered_map<int, bool>visited4; 
    vector<int>Shortestpath(int start, int dest) { 
        //first of all we'll perform bfs 
        queue<int>q;  
        q.push(start); 
        parent1[start] = -1; 
        visited4[start] = true; 
        while (!q.empty()) {
            int front = q.front(); 
            q.pop();  
            for (auto i : adj[front]) {
                if (!visited4[i]) {
                    q.push(i);  //take iske adjacents ko dekhen 
                    visited4[i] = true; 
                    parent[i] = front;   
                }
            }
        }
        //ab hum shortest path dekhne ke liye reverse traverse karenge 
        int currentNode = dest;  vector<int>ans; 
        ans.push_back(start); 
        while (start != currentNode) {
            currentNode = parent[currentNode];
            ans.push_back(currentNode); 
        }
        reverse(ans.begin(), ans.end()); 
        return ans;  
    }
};

int main() {
    graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);

    cout << "Printing Graph: " << endl;
    g.print();

    cout << "\nBFS: ";
    g.bfs(1);

    cout << "\nDFS: ";
    g.dfs(1);

    cout << "\nDetecting Cycle: ";
    if (g.detectCycle(1)) {
        cout << "Cycle detected!";
    }
    else {
        cout << "No cycle detected!";
    }

    cout << "\nTopological Sort: ";
    g.printtopsort();

    return 0;
}
