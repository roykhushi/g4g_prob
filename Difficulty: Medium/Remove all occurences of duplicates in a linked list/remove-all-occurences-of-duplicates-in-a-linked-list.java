//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GFG {
    Node head;
    Node tail;

    public void addToTheLast(Node node) {
        if (head == null) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            tail = node;
        }
    }

    void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    /* Drier program to test above functions */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int N = sc.nextInt();
            GFG llist = new GFG();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < N; i++) {
                int a = sc.nextInt();
                llist.addToTheLast(new Node(a));
            }

            Solution ob = new Solution();
            head = ob.removeAllDuplicates(llist.head);
            llist.printList(head);

            t--;
        }
    }
}
// } Driver Code Ends


class Solution {
    public Node removeAllDuplicates(Node head) {
        // code here
        if(head == null){
            return null;
        }
        if(head.next == null){
            return head;
        }
        Node curr = head;
        Node prev = head;
        
        while(curr != null && curr.next != null){
            Node temp = curr.next;
            if(curr.data != temp.data){//simply aage badh jao
                prev = curr;
                curr = temp;
            }
            else{//delete 
                int val = curr.data;
                if(curr == head){
                    while(head!= null && head.data == val){
                        head = head.next;
                    }
                    prev = head;
                    curr = head;
                }
                else{
                    while(curr != null && curr.data == val){
                        curr = curr.next;
                    }
                    prev.next = curr;
                }
            }
        }
        return head;
    }
}