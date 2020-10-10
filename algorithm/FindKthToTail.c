#include <stdio.h>


Node* removeValue(Node* head, int k)
{

   if(node ==nullptr || k ==0)
      return   nullptr;
   Node* pBegin = head;
   Node* pFirst = nullptr;
   
   for(int i=0;i<k-1;i++)
   {
       if(pBegin->next !=nullptr)
       {
            pBegin  =  pBegin->next;
       }
       else
       {
            return nullptr;
       }
   }
   
   pFirst = head;
   
   while(pBegin->next !=nullptr)
   {
      pBegin = pBegin->next;
      pFirst = pFirst->next;
   }
   
   return  pFirst;
}

