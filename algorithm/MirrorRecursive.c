#include <stdio.h>


void MirrorRecursiveLy(Node* node)
{
   if(node == nullptr)
      return;
   
   if(node->left==nullptr && node->right==nullptr)
      return;
     
   Node* temp = node->left;
   
   node->left = node->right;
   
   node->right = temp;
   
   if(node->left)
      MirrorRecursiveLy(node->left);
      
   if(node->right)
      MirrorRecursiveLy(node->rights);

} 

