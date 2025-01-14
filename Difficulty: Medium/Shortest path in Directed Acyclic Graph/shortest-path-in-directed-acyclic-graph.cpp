//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfsTopoSort(int node,vector<vector<pair<int,int>>> &adj,stack<int> &st,
        unordered_map<int,bool> &visited){
            visited[node] = 1;
            for(auto i : adj[node]){
                int v = i.first;
                if(!visited[v]){
                    dfsTopoSort(v,adj,st,visited);
                }
            }
            st.push(node);
        }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back(make_pair(v,wt));
        }
        
        stack<int> st;
        unordered_map<int,bool> visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsTopoSort(i,adj,st,visited);
            }
        }
        
        vector<int> dist(V,1e9); //INT_MAX might give overflow
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto i : adj[node]){
                int v = i.first;
                int wt = i.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node]+wt;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends