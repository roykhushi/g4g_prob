//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        //brute force -> O(n2) --> tle
        // int n = arr.size();
        
        // int totWater = 0;
        
        // for(int i=0;i<n;i++){
        //     int leftMax = 0;
        //     int rightMax = 0;
        //     //finding higest building at left of i
        //     for(int j=0;j<i;j++){
        //         leftMax = max(leftMax,arr[j]);
        //     }
            
        //     //finding right max to right of i
        //     for(int j=i+1;j<n;j++){
        //         rightMax = max(rightMax,arr[j]);
        //     }
            
        //     int water = max(0,min(leftMax,rightMax)-arr[i]);
            
        //     totWater+=water;
            
        // }
        
        // return totWater;
        
        //optimised
        
        int n = arr.size();
        
        
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        //filling leftMax
        leftMax[0] = arr[0];
        
        for(int i=1;i<n;i++){
            leftMax[i] = max(arr[i],leftMax[i-1]);
        }
        
        //filling right max;
        rightMax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(arr[i],rightMax[i+1]);
        }
        
        int totWater = 0;
        
        for(int i=0;i<n;i++){
            totWater+= max(0,min(leftMax[i],rightMax[i])-arr[i]);
        }
        
        return totWater;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends