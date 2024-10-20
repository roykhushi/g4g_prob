//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n=post_exp.length();
        stack<string>st;
        for(int i=0;i<n;i++)
        {
            if(isalnum(post_exp[i]))
            {
                 st.push(string(1, post_exp[i]));
            }
            else
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string conv=post_exp[i]+b+a;
                st.push(conv);  // Push the result back to the stack
            }
        }
        // The top of the stack contains the final infix expression
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends