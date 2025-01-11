//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int> mp;
        int n = s.length();
        int i = 0;
        int maxLen = 0;
        
        for(int j=0;j<n;j++){
            //duplicate char mila 
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i){
                i = mp[s[j]]+1;
            }
            mp[s[j]] = j;
            maxLen = max(maxLen,j-i+1);
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends