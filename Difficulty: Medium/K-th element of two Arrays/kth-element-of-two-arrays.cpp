//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        //optimised
        int n = a.size();
        int m = b.size();
        int count = 0;
        
        int i=0;
        int j=0;
        int elem = -1;
        while(i<n && j<m){
            
            if(a[i]<b[j]){
                elem = a[i];
                i++;
                count++;
            }
            else{
                elem = b[j];
                j++;
                count++;
            }
            
            if(count == k){
                return elem;
            }
        }
        
        while(i<n){
            count++;
            elem = a[i++];
            
            if(count == k){
                return elem;
            }
        }
        
        while(j<m){
            count++;
            elem = b[j++];
            
            if(count == k){
                return elem;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends