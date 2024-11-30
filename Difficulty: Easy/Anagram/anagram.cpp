//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int n = s1.length();
        int m = s2.length();
        
        if(n != m){
            return false;
        }
        //freq vec
        vector<char> c1(26);
        vector<char> c2(26);
        
        for(int i=0;i<n;i++){
            c1[s1[i]-'a']++;
        }
        for(int j=0;j<m;j++){
            c2[s2[j]-'a']++;
        }
        return c1 == c2;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends