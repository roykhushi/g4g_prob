//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.firstElement(n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    static int firstElement(int n) {
        // code here
        if(n == 0 || n == 1){
            return 1;
        }
        int mod = 1000000007;
        
        int[][] mat = new int [2][2];
        
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
        
        int a = 1;
        int b = 1;
        int c = 1;
        int d = 0;
         
        int [][] scnd = new int[2][2];
        
        for(int i=2;i<=n;i++){
            
            scnd[0][0] = (mat[0][0]*a + mat[0][1]*c)%mod;
            scnd[0][1] = (mat[0][1]*b + mat[0][1]*d)%mod;
            scnd[1][0] = (mat[1][0]*a + mat[1][1]*c)%mod;
            scnd[1][1] = (mat[1][0]*b + mat[1][1]*d)%mod;
            
            a = scnd[0][0];
            b = scnd[0][1];
            c = scnd[1][0];
            d = scnd[1][1];
        }
        
        return (scnd[1][0])%mod;
    } 
}