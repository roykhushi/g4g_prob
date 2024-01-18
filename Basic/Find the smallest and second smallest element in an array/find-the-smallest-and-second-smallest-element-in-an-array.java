//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            long n = Long.parseLong(br.readLine().trim());
            long a[] = new long[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(inputLine[i]);
            }
            
            Compute obj = new Compute();
            long[] product = obj.minAnd2ndMin(a, n); 
            if(product[0]==-1)
                System.out.println(product[0]);
            else
                System.out.println(product[0]+" "+product[1]);
            
        }
	}
}


// } Driver Code Ends


//User function Template for Java


class Compute 
{
    public long[] minAnd2ndMin(long a[], long n)  
    {
        long [] result = {-1,-1};
        long min1 = Long.MAX_VALUE;
        long min2 = Long.MAX_VALUE;
        for(int i =0;i<n;i++){
            if(a[i] < min1){
                min2 = min1;
                min1 = a[i];
            }
            else if(a[i] != min1 && a[i] <= min2){
                min2 = a[i];
            }
        }
         if(min2==Long.MAX_VALUE) 
         {
             min2 = -1;
             min1 = -1;
             
         }
        result[0] = min1;
        result[1] = min2;
        return result;
    }
}
