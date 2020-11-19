#include <stdio.h>

int pathSum(TreeNode*  root, int sum)
{

    return root? pathSumStartWithRoot(root, sum)
          + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;

}

int pathSumStartWithRoot(TreeNode* root, int sum)
{

    if(!root)
       return 0;
       
    int  count =  root->val == sum ? 1:0;
    count += pathSumStartWithRoot(root->left, sum - root->val);
    count += pathSumStartWithRoot(root->right, sum - root->val);
    
    return count;

}
