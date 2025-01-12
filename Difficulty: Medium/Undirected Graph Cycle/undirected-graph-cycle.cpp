//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//using bfs
class Solution {
  public:
    bool checkCycle(int node,unordered_map<int,bool> &visited,vector<vector<int>>& adj){
        unordered_map<int,int> parent;
        parent[node] = -1;
        visited[node] = 1 ;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto i: adj[frontNode]){
                if(visited[i] && i != parent[frontNode]){
                    return true;
                }
                else if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = frontNode;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool> visited;
        int v = adj.size();
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool ans = checkCycle(i,visited,adj);
                
                if(ans){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends