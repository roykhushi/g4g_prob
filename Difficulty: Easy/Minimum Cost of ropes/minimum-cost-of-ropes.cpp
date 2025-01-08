//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        //using min-heap to get the min element and adding them
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0;i<arr.size();i++){
            minHeap.push(arr[i]);
        }
        
        int cost = 0;
        
        while(minHeap.size() > 1){
            int min1 = minHeap.top();
            minHeap.pop();
            
            int min2 = minHeap.top();
            minHeap.pop();
            
            int sum = min1+min2;
            cost+=sum;
            
            minHeap.push(sum);
        }
        
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends