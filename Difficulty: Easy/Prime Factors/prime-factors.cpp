//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	
	bool isPrime(int n){
	    for(int i=2;i<=sqrt(n);i++){
	        if(n%i == 0){
	            return false;
	        }
	    }
	    return true;
	}
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int> ans;
	    
	    for(int i=2;i<=N;i++){
	        if((N%i) == 0 && isPrime(i)){
	            ans.push_back(i);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends