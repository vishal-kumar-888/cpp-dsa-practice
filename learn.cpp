#include <iostream>
#include <vector>
using namespace std;

// geven n nodes and m edges,
// how to represent a graph in C++?
// There are several ways to represent a graph in C++. The two most common methods are: method 1: Adjacency Matrix and method 2: Adjacency List.

int main() {
    // Method 1: Adjacency Matrix (simple but uses more memory)
    int matrix[5][5] = {0};  // 5x5 grid all zeros
    matrix[0][1] = 1;  // Edge between 0 and 1
    matrix[1][0] = 1;  // Same edge (undirected)
    
    // Method 2: Adjacency List (better for most cases)
    vector<int> graph[5];  // Array of 5 vectors
    graph[0].push_back(1);  // 0 is connected to 1
    graph[1].push_back(0);  // 1 is connected to 0
    
    cout << "Graph created successfully!" << endl;

    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    int Adjacency[n+1][m+1];  // Create an adjacency matrix based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        Adjacency[u][v] = 1;  // Mark the edge in the adjacency matrix
        Adjacency[v][u] = 1;  // Mark the edge in the adjacency matrix (undirected)
    }

    vector<int> adjList[n+1];  // Create an adjacency list based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        adjList[u].push_back(v);  // Add v to u's list
        adjList[v].push_back(u);  // Add u to v's list (undirected)
    }

    // directed graph
    vector<int> directedAdjList[n+1];  // Create an adjacency list for directed graph based on user input
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter directed edge (u v): ";
        cin >> u >> v;
        directedAdjList[u].push_back(v);  // Add v to u's list (directed)
    }

    // weighted graph
    vector<pair<int, int>> weightedAdjList[n+1];  // Create an adjacency list for weighted graph based on user input
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter weighted edge (u v w): ";
        cin >> u >> v >> w;
        weightedAdjList[u].push_back({v, w});  // Add v and weight to u's list (directed)
        weightedAdjList[v].push_back({u, w});  // Add u and weight to v's list (undirected)
    }   
    
    // connected components
    vector<int> visited(n+1, 0);  // Create a visited array for DFS
    vector<vector<int>> connectedComponents;  // To store connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> component;  // To store the current component
            dfs(i, graph, visited, component);  // Perform DFS to find the component
            connectedComponents.push_back(component);  // Add the component to the list of components
        }
    } 
}