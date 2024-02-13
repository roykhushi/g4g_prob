//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            
            String S[] = read.readLine().split(" ");
            int[] arr = new int[N];
            
            for(int i=0; i<N; i++)
                arr[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            System.out.println(ob.makeProductOne(arr,N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int makeProductOne(int[] arr, int n) {
        // code here
        int pos = 0;
        int neg = 0;
        int zero = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                neg +=1;
                sum += Math.abs(arr[i])-1;
            }
            else if(arr[i]>0){
                pos+=1;
                sum += arr[i]-1;
            }
            else{
                sum+=1;
                zero +=1;
            }
        }
        if(neg%2 != 0 && zero == 0){
            return sum+=2;
        }
        return sum;
    }
};