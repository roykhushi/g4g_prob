//{ Driver Code Starts
// Initial template for Java
import java.util.*;
import java.io.*;
class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S1 = read.readLine();
            String S2 = read.readLine();
            Solution ob = new Solution();

            System.out.println(ob.areAnagram(S1, S2));
        }
    }
}
// } Driver Code Ends


// User function template for Java
class Solution {
    static int areAnagram(String S1, String S2) {
        // code here
        char [] str1 = S1.toCharArray();
        char [] str2 = S2.toCharArray();
        
        Arrays.sort(str1);
        Arrays.sort(str2);
        
        int n = str1.length;
        int m = str2.length;
        
        if(n!=m){
            return 0;
        }
        if(Arrays.equals(str1,str2)){
            return 1;
        }
        return 0;
    }
}