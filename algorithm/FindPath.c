#include <stdio.h>

void FindPath(Node* root,int sum)
{

   if(root==nullptr)
       return;
   
   std::vector<int> path;
   
   int current = 0;
   
   FindPath(root,sum,path,current);


}

void FindPath(Node* root,int sum,std::vector<int>& path, int current)
{

   current += root->value;
   
   path.push_back(root->value);
   
   boot isLeaf = root->left ==nullptr && root->right == nullptr;
   
   if(current == sum && isLeaf)
   {
      printf("have path");
      
      std::vector<int>::iterator iter = path.begin();
      
      for(;iter!=path.end();iter++)
      {
         printf("%d",*iter);
      }
   }
   
   if(root->left!=nullptr)
       FindPath(root->left,sum,path,current);

   if(root->right!=nullptr)
       FindPath(root->right,sum,path,current);
       
   path.pop_back(); 
}
