#include <stdio.h>


Node* meetingNode(Node* head)
{

   if(head ==nullptr)
      return   nullptr;
   Node* pSlow = head->next;
   if(pSlow->next==nullptr)
        return nullptr;
   
   Node* pFast = pSlow->next;

   while(pFast!=nullptr && pSlow!=nullptr)
   {
      if(pFast==pSlow)
         return pFast;
      pSlow = pSlow->next;
      
      pFast = pFast->next;
      if(pFast!=nullptr)
           pFast = pFast->next;
   }
   
   return  nullptr;
}

Node* FindLoopNode(Node* head)
{
    if(head==nullptr)
       return  nullptr;
    Node* meetingNode = meetingNode(head);
    
    int num=1;
    Node* loopNode = meetingNode;
    while(loopNode->next ==meetingNode)
    {
        loopNode = loopNode->next;
        num++;
    }
    
    Node* pFirst = head;
    for(int i=0;i<num;i++)
    {
       pFirst = pFirst->next;
    }
    
    Node* pSecond = head;
    while(pFirst!=pSecond)
    {
       pFirst=pFirst->next;
       pSecond=pSecond->next;
    }
    
    return pFirst;
}

