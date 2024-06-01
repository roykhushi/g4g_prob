//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            String s;
            s = br.readLine();
            
            Solution obj = new Solution();
            String res = obj.encode(s);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static String encode(String s) {
        // code here
        StringBuilder sb = new StringBuilder();
        
        
        int n = s.length();
        for(int i=0;i<s.length();i++){
            int count = 1;
            char curr = s.charAt(i);
            while(i<n-1 && s.charAt(i+1) == curr){
                count +=1;
                i+=1;
            }
            sb.append(curr);
            sb.append(count);
        }
        return sb.toString();
    }
}
    