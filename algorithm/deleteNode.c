#include <stdio.h>


Node removeValue(Node head, int num)
{
      while(head!=NULL)
      {
          if(head.value  !=num)
             break;
          head =  head.next;
      }
      Node pre = head;
      Node cur = head;
      while(cur!=NULL)
      {
          if(cur.value == num)
          {
             pre.next  = cur.next;
          }
          else
          {
             pre = cur;
          }
          cur = cur.next;
      }
      
      return  head;
}

