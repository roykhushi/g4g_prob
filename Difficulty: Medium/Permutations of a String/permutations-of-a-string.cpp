//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(set<string>&st, string &s, int idx){
        if(idx >= s.length()){
            st.insert(s);
            return;
        }
        for(int i=idx;i<s.length();i++){
            swap(s[idx],s[i]);
            solve(st,s,idx+1);
            swap(s[idx],s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> st;
        solve(st,s,0);
        vector<string> ans;
        for(auto e : st){
            ans.push_back(e);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends