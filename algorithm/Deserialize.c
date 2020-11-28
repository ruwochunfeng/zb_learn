#include <stdio.h>

void Deserialize(BinaryTreeNode** root, istream& stream)
{
   int number;
   if(ReadStream(stream, &number))
   {
      *root = new BinaryTreeNode();
      (*root)->value = number;
      (*root)->left = nullptr;
      (*root)->right = nullptr;
      
      Deserialize(&((*root)->left),stream);
      Deserialize(&((*root)->right),stream);  
   }

}
