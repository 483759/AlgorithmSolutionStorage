package Java;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  public static class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }

  public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      int carry = 0;
      ListNode node = new ListNode();
      ListNode head = node;
      
      while(l1!=null || l2!=null){
          int sum=carry;

          if(l1!=null){
            sum+=l1.val;
            l1=l1.next;
          }
          if(l2!=null){
            sum+=l2.val;
            l2=l2.next;
          }
          
          carry = (sum>=10)?1:0;
          
          node.next = new ListNode((sum%10));
          node=node.next;
      }
      
      if(carry!=0){
        node.next=new ListNode(carry);
      }
      
      return head.next;
  }

  public static void main(String[] args) {
    Integer k = 0;
    for(Integer i = k; i < 10; i++){
      System.out.println(i==k);
      System.out.println(i);
    }
    System.out.println(k);
    // ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    // ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // ListNode node = addTwoNumbers(l1, l2);
    // while(node!=null){
    //   System.out.println(node.val);
    //   node=node.next;
    // }
  }
}