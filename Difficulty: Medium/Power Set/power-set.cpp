//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
	    void solve(string& s, int idx, string temp, vector<string>&ans){
	        if(idx == s.length()){
	            //empty string edgec ase
	            if(temp.length()>0){
	                ans.push_back(temp);
	            }
	            return;
	        }
	        
	        //not adding current char
	        solve(s,idx+1,temp,ans);
	        
	        temp+=s[idx];
	        
	        //adding curr char
	        solve(s,idx+1,temp,ans);
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int idx = 0;
		    string temp = "";
		    vector<string> ans;
		    
		     solve(s,idx,temp,ans);
		     
		     sort(ans.begin(),ans.end());
		     
		     return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends