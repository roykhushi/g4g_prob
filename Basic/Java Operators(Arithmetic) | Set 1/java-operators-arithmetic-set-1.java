//{ Driver Code Starts

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String [] S1 = br.readLine().trim().split(" ");
            int A = Integer.parseInt(S1[0]);
            int B = Integer.parseInt(S1[1]);
            int C = Integer.parseInt(S1[2]);
            Solution ob = new Solution();
            double[] ans = ob.FindRoots(A, B, C);
            if(ans.length == 1){
                System.out.println((int)ans[0]);
                continue;
            }
            for(int i = 0; i < ans.length; i++)
                System.out.print(String.format("%6f", ans[i]) + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends



class Solution
{
    public double[]  FindRoots(int a, int b, int c)
    {
        // code here
        double delta = (b*b - 4*a*c);
        if(delta < 0)
            return new double[]{-1d};
            
        double x1 = (-1*b + Math.sqrt(delta))/(2*a);
        double x2 = (-1*b - Math.sqrt(delta))/(2*a);
        
        double[] roots = new double[2];
        if(x1 > x2){
            roots[0] = x2;
            roots[1] = x1;
        }else{
            roots[1] = x2;
            roots[0] = x1;
        }
        return roots;
    }
}