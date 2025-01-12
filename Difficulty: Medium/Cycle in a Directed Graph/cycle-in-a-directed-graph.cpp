//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkCycleDfs(int node,unordered_map<int,bool> &visited,
        unordered_map<int,bool> &dfsVis,vector<vector<int>> adj){
            visited[node] = 1;
            dfsVis[node] = 1;
            
            for(auto i: adj[node]){
                if(!visited[i]){
                    bool flag = checkCycleDfs(i,visited,dfsVis,adj);
                    if(flag){
                        return true;
                    }
                }
                else if(dfsVis[i]){
                    return true;
                }
            }
        dfsVis[node] = false;    
        return false;    
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVis;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans = checkCycleDfs(i,visited,dfsVis,adj);
                if(ans){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends