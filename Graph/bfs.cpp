#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph {
    int V; // number of vertices
    vector<int> adjList[100]; // adjacency list
public:
    Graph(int V) {
        this->V = V;
    }
    
    // Method to add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
    
    // Make adjacency list accessible to BFS
    vector<int> getAdjList(int vertex) {
        return adjList[vertex];
    }
    
    int getV() {
        return V;
    }
};

class solution {
public:
    void bfs(Graph g, int start) {
        vector<bool> visited(100, false); // visited array
        queue<int> q; // queue for BFS
        
        q.push(start); // start BFS from the given node
        visited[start] = true; // mark the start node as visited
        
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " "; // Process the current node
            
            // Visit all neighbors of current node
            vector<int> neighbors = g.getAdjList(current);
            for(int neighbor : neighbors) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

//  adjacency matrix representation of graph
 
class GraphMatrix {
    int V; // number of vertices
    int adjMatrix[100][100]; // adjacency matrix
public:
    GraphMatrix(int V) {
        this->V = V;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0; // initialize all entries to 0
            }
        }   
    }

    // add edge to the graph
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // mark the edge in the adjacency matrix
        adjMatrix[v][u] = 1; // mark the edge in the adjacency matrix (undirected)
    }
   
     

};

class solutionMatrix {
public:    
    vector<int> getAdjMatrix(GraphMatrix g, int vertex) {
        vector<int> neighbors;
        for(int i = 0; i < g.getV(); i++) {
            if(g.adjMatrix[vertex][i] == 1) { // Check if there is an edge
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }
    void bfsMatrix(GraphMatrix g, int start) {
        vector<bool> visited(100, false); // visited array
        queue<int> q; // queue for BFS
        
        q.push(start); // start BFS from the given node
        visited[start] = true; // mark the start node as visited
        
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " "; // Process the current node
            
            // Visit all neighbors of current node
            vector<int> neighbors = getAdjMatrix(g, current);
            for(int neighbor : neighbors) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Graph g(6);
    
    // Add edges
    g.addEdge(0, 1);   
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    
    solution sol;
    //cout << "BFS starting from node 0: ";
    //sol.bfs(g, 5); // Output: 0 1 2 3 4 5

    vector<int> list = g.getAdjList(5);
    cout << "Adjacency list for node : ";
    for(int neighbor : list) {
        cout << neighbor << " ";
    }
    cout << endl;
    
    int n =3;

    vector<vector<int>> edges;

    vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    
    return 0;
}