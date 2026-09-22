#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }
    
    // DFS Recursive (with connected components detection)
    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }
    
    // Handle disconnected graphs
    void dfsTraversal() {
        vector<bool> visited(V, false);
        int components = 0;
        
        cout << "DFS Traversal by Components:\n";
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                components++;
                cout << "Component " << components << ": ";
                dfsUtil(i, visited);
                cout << "\n";
            }
        }
        cout << "Total Components: " << components << "\n\n";
    }
    
    // BFS (also handles disconnected graphs)
    void bfsTraversal() {
        vector<bool> visited(V, false);
        queue<int> q;
        int components = 0;
        
        cout << "BFS Traversal by Components:\n";
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                components++;
                cout << "Component " << components << ": ";
                
                visited[i] = true;
                q.push(i);
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    cout << node << " ";
                    
                    for(int neighbor : adj[node]) {
                        if(!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                cout << "\n";
            }
        }
        cout << "Total Components: " << components << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    g.dfsTraversal();
    g.bfsTraversal();
    
    return 0;
}