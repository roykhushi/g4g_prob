//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> st1;
    stack<int> st2;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st1.push(x);
        
        int top = (st2.empty()) ? INT_MAX : st2.top();
        
        if(x < top){
            st2.push(x);
        }
        else{
            st2.push(top);
        }
        
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st1.empty()){
            st1.pop();
            st2.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st1.empty()){
            return st1.top();
        }
        return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st2.empty()){
            return st2.top();
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends