//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int canPlaceCows(vector<int> &stalls,int dist, int k){
        int cows = 1;
        int last = stalls[0];
        
        int n = stalls.size();
        
        for(int i=0;i<n;i++){
            if(stalls[i]-last >= dist){
                cows++;
                last = stalls[i];
            }
        }
        if(cows >= k){
            return 1;
        }
        return 0;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        
        int n = stalls.size();
        
        sort(stalls.begin(),stalls.end());
        
        int start = 0;
        int end = (stalls[n-1]-stalls[0]);
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(canPlaceCows(stalls,mid,k)){
                start = mid+1;
            }
            else{
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