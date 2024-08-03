//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int N = sc.nextInt();
            int M[][] = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    M[i][j] = sc.nextInt();
                }
            }
            System.out.println(new Solution().celebrity(M));
            t--;
        }
    }
}
// } Driver Code Ends




//User function Template for Java


class Solution
{ 
    
    public static boolean knows(int a,int b, int M[][]){
        if(M[a][b] == 1){
            return true;
        }
        return false;
    }
    
    int celebrity(int M[][])
    {
        int n = M.length;
        if(n == 1){
            return 0;
        }
    	Stack<Integer> s = new Stack<>();
    	
    	//step1 
    	for(int i=0;i<n;i++){
    	    s.push(i);
    	}
    	
    	//step2
    	while(s.size()>1){
    	    int a = s.pop();
    	    int b = s.pop();
    	    
    	    if(knows(a,b,M)){
    	        s.push(b);
    	    }
    	    else{
    	        s.push(a);
    	    }
    	    int candidate = s.peek();
    	    
    	    boolean flag1 = false;
    	    //check in row
    	    int count_zero = 0;
    	    for(int i=0;i<n;i++){
    	        if(M[candidate][i] == 0){
    	            count_zero+=1;
    	        }
    	    }
    	    if(count_zero == n){
    	        flag1 = true;
    	    }
    	    
    	    //check for col
    	    boolean flag2 = false;
    	    int count_one = 0;
    	    for(int i=0;i<n;i++){
    	        if(M[i][candidate] == 1){
    	            count_one+=1;
    	        }
    	    }
    	    if(count_one == n-1){
    	        flag2 = true;
    	    }
    	    if(flag1 == true && flag2 == true){
    	        return candidate;
    	    }
    	}
    	return -1;
    }
}