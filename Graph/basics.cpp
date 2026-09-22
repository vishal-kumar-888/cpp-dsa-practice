#include <vector>
#include <iostream>
using namespace std;
// clang++ basics.cpp -o b && ./b
void UndirectedUnweighted()
{
    // Step 1: Define the graph
    int n = 5; // Number of vertices (0 to 4)

    // Step 2: Create Adjacency List
    // vector<int> adj[n];  // Static array of vectors (Works in C++)
    vector<vector<int>> adj(n); // Dynamic - More flexible

    // Step 3: Add edges (UNDIRECTED)
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // CRITICAL: Undirected means add both ways
    }

    // Step 4: Print the graph to verify
    cout << "Adjacency List Representation:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << " is connected to: ";
        for (int neighbor : adj[i])
        {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}

void DirectedWeighted()
{
    int n = 4;

    // Step 1: Vector of vectors of PAIRS (neighbor, weight)
    vector<vector<pair<int, int>>> adj(n);

    // Step 2: Add DIRECTED weighted edges
    vector<tuple<int, int, int>> edges = {
        {0, 1, 5000}, // Delhi -> Mumbai, cost 5000
        {0, 2, 4000}, // Delhi -> Bangalore, cost 4000
        {1, 3, 3000}, // Mumbai -> Chennai, cost 3000
        {2, 3, 2500}, // Bangalore -> Chennai, cost 2500
        {3, 0, 6000}  // Chennai -> Delhi, cost 6000
    };

    for (auto [u, v, w] : edges)
    {
        adj[u].push_back({v, w}); // ONLY one direction (DIRECTED)
    }

    // Step 3: Print with weights
    cout << "Weighted Directed Graph:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "From City " << i << ":\n";
        for (auto [neighbor, weight] : adj[i])
        {
            cout << "  → City " << neighbor << " (₹" << weight << ")\n";
        }
    }
}

void directedCyclic(

)
{
    int n = 6;
    vector<vector<int>> adj(n);

    // Add directed edges (prerequisites)
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 3}, // Math -> Physics, Math -> CS101
        {1, 4},         // Physics -> Data Structures
        {3, 4},         // CS101 -> Data Structures
        {4, 5},         // Data Structures -> Algorithms
        {2, 5}          // Chemistry -> Algorithms
    };

    for (auto [u, v] : edges)
    {
        adj[u].push_back(v);
    }

    // Calculate IN-DEGREE for every node (CRITICAL for DAGs)
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; u++)
    {
        for (int v : adj[u])
        {
            inDegree[v]++;
        }
    }

    cout << "In-Degree of each course:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Course " << i << " has " << inDegree[i] << " prerequisites\n";
    }
}

int main()
{
    // DirectedWeighted();
    // UndirectedUnweighted();
    directedCyclic();
    return 0;
}