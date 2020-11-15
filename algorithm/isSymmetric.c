#include <stdio.h>

bool isSymmetric(TreeNode *root)
{

   return root? isSymmetric(root->left, root->right) : true;

}


bool isSymmetric(TreeNode * left, TreeNode * right)
{
   if(!left && !right)
      return true;
     
     
   if(!left || !right)
      return false;
      
   
   return isSymmetric(left->left, right-right) && isSymmetric(right- >left,right->left); 

}
