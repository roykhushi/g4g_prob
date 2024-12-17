//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool canPlaceCows(vector<int> &stalls,int dist, int k){
      int cow = 1;
      int lastStall = stalls[0];
      int n = stalls.size();
      
      for(int i=0;i<n;i++){
          if(stalls[i]-lastStall >= dist){
              cow+=1;
              lastStall = stalls[i];
          }
      }
      if(cow >= k){
          return true;
      }
      return false;
  }
  
  

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int start = 0;
        int end = stalls[n-1]-stalls[0];
        int ans = 0;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(canPlaceCows(stalls,mid,k)){
                start = mid+1;
            }
            else{
                // ans = end;
                end = mid-1;
            }
        }
        return end;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends