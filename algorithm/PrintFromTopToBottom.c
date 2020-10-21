#include <stdio.h>

void printFromTopToBottom(Node* root)
{
   if(!root)
      return;
     
   std::deque<Node*> deque;
   
   deque.push_back(root);
   
   while(deque.size())
   {
      Node* node = deque.front();
      deque.pop_front();
      
      printf("%d", node->value);
      
      if(node->left)
             deque.push_back(node->left);
      if(node->right)
             deque.push_back(node->right);
   }

}

