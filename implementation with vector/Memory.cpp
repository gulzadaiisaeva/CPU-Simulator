/* 
 * File:   Memory.cpp
 * Author: Gulzada IISAEVA - 131044085
 * 
 * Bu classta Memory classindaki fonskiyonlarin implementationlari vardir
 */

#include "Memory.h"

Memory::Memory(const int  option) {
    setMemoryZero(0);
}
 void Memory::setMemoryZero(const int val)
 {
      for (int k = 0; k < 50; ++k)
    {
    	myMemAddress[k]=val;
    }
 }
 void Memory::setMem(const int index, const int value)
 {
     myMemAddress[index]=value;
 }
  void Memory::printAll() const 
{
     for (int k = 0; k < 50; ++k)
    {
         cout << "Memory ["<<k<<"]  -> "<< getMem(k)<< endl;
    } 
}


