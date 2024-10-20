//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        
        int n=pre_exp.length();
        stack<string>st;
        for(int i=n-1;i>=0;i--)
        {
            if(isalnum(pre_exp[i]))
            {
                 st.push(string(1, pre_exp[i]));
            }
            else
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string conv=a+b+pre_exp[i];
                st.push(conv);  
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends