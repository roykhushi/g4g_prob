//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<vector<int>> &adj, vector<int> &ans, int node, unordered_map<int,bool> &visited){
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            ans.push_back(frontNode);
            
            for(auto i: adj[frontNode]){//traversing the neighbours
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        if(!visited[0]){
            bfs(adj,ans,0,visited);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends