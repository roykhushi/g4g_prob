//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int step = 0;
        int count = 0;
        
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]>arr[i]){
                step+=1;
            }
            else{
                count = max(step,count);
                step = 0;
            }
        }
        count = max(step,count);
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends