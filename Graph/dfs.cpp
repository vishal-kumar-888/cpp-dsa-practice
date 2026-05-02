#include<iostream>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector<int> *adjList;
public:
    Graph(int V){
        this->V = V;
        adjList = new vector<int>[V];
    }
    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    ~Graph(){
        delete[] adjList;
    }
    friend class DFS;
};

class DFS{
    void dfsUtil(int v, vector<bool> &visited, Graph &g){
        visited[v] = true;
        cout << v << " ";
        for(int i : g.adjList[v]){
            if(!visited[i]){
                dfsUtil(i, visited, g);
            }
        }
    }
public:
    void dfs(Graph &g, int start){
        vector<bool> visited(g.V, false);
        dfsUtil(start, visited, g);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    DFS dfs;
    cout << "DFS starting from vertex 0: ";
    dfs.dfs(g, 0);
    cout << endl;

    return 0;
}