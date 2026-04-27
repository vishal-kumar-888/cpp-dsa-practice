class Solution {
public:
     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        return dfs(adj, visited, source, destination);
    }
    
private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int current, int destination) {
        if (current == destination) {
            return true;
        }
        
        visited[current] = true;
        
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                if (dfs(adj, visited, neighbor, destination)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
