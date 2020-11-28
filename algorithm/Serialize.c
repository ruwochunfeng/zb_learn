#include <stdio.h>

void Serialize(BinaryTreeNode* pRoot, ostream& stream)
{
   if(pRoot == nullptr)
   {
      stream << "$,";
      return;
   }
   
   stream << pRoot->m_nValue << ',';
   
   Serialize(pRoot->m_pLeft, stream);
   Serialize(pRoot->m_pRight, stream);
}
