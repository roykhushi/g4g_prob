//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        //brute force = O(n2)
        // int n = arr.size();
        // int maxSize = 0;
        
        // for(int i=0;i<n;i++){
        //     int c_zero = 0;
        //     int c_one = 0;
            
        //     for(int j=i;j<n;j++){
        //         if(arr[j] == 0){
        //             c_zero++;
        //         }
        //         else{
        //             c_one++;
        //         }
                
        //         if(c_zero == c_one){
        //             maxSize = max(maxSize,j-i+1);
        //         }
        //     }
        // }
        
        // return maxSize;
        
        //optimised
        map<int,int> mp;
        int n = arr.size();
        int maxSize = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum == 0){
                maxSize = max(maxSize,i+1);
            }
            
            if(mp.find(sum) != mp.end()){
                 maxSize = max(maxSize,i-mp[sum]);
            }
            else{
                mp[sum] =i;
            }
            
        }
        
        return maxSize;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends