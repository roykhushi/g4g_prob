//{ Driver Code Starts
// driver

import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GfG{
    
    static void printList(Node n){
        while(n!=null){
            System.out.print(n.data+" ");
            n = n.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            
            int n = sc.nextInt();
            int val = sc.nextInt();
            
            Node num1 = new Node(val);
            Node tail = num1;
            for(int i=0; i<n-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            int m = sc.nextInt();
            val = sc.nextInt();
            
            Node num2 = new Node(val);
            tail = num2;
            for(int i=0; i<m-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            Solution g = new Solution();
            Node res = g.addTwoLists(num1, num2);
            printList(res);
        }
    }
}

// } Driver Code Ends


/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution{
     private static Node removeZeroes(Node node)

    {

        while(node!=null&&node.data==0)

        {

            node=node.next;

        }

        if(node==null)

        return new Node(0);

        else

        return node;

    }
    //Function to add two numbers represented by linked list.
    static Node reverse(Node head){
        
        Node curr = head;
        Node prev = null;
        while(curr != null){
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    } 
    static Node addTwoLists(Node num1, Node num2){
        // code here
        // return head of sum list
        // if(num1.data == 0 && num2.data == 0){
        //     return new Node(0);
        // }
        num1 = removeZeroes(num1);
        num2 = removeZeroes(num2);
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node dummy = new Node(0);
        Node temp1 = num1;
        Node temp2 = num2;
        Node curr = dummy;
        int carry = 0;
        while(temp1 != null || temp2 != null || carry == 1){
            int sum = 0;
            if(temp1 != null){
                sum += temp1.data;
                temp1 = temp1.next;
            }
            if(temp2 != null){
                sum += temp2.data;
                temp2 = temp2.next;
            }
            
            sum += carry;
            carry = sum/10;
            Node node = new Node(sum%10);
            curr.next = node;
            curr = curr.next;
            
        }
        dummy = reverse(dummy.next);
        
        // Node zero = dummy;
        // if(zero.data == 0){
        //     zero = zero.next;
        // }
        return dummy;
    }
}