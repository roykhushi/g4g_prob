//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        //kmp lagega 
        
        string temp = s1+s1;
        
        int i = 0;
        int j = 0;
        
        while(i<temp.length() && j<s2.length()){
            if(temp[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return j == s2.length();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends