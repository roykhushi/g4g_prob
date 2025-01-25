//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        // using heap method
        
        //step 1 -> building a max heap for the 1st k elements
        priority_queue<int> pq;
        
        for(int i=0;i<k;i++){ //o(n)
            pq.push(arr[i]);
        }
        
        //step 2 -> for the rest elements i.e, k->n-1 elems do this:
        //(i) if element < heap.top() --> heap.pop() --> heap.push(elem)
        //(ii)in the end the heap would contain the k elems nd
        //final ans would be heap.top();
        
        int n = arr.size();
        for(int i=k;i<n;i++){ //O(n-k)
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends