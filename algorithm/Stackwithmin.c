#include <stdio.h>

template<typename T>
void stackwithMin<T>::push(const T& value)
{

  m_data.push(value);
  
  if(min.size() == 0 || value < min.top())
      min.push(value);
  else
      min.push(min.pop());

}

template<typename T>
void stackwithMin<T>::pop()
{
  assert(m_data.size()>0 && min.size()>0);
  m_data.pop();
  min.pop();

}

template<typename T>
const T& stackwithMin<T>::min()
{
  assert(m_data.size()>0 && min.size()>0);

  return min.top();

}


