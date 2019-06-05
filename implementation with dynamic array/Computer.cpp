/* 
 * File:   Computer.cpp
 * Author: Gulzada IISAEVA - 131044085
 * 
 * Bu classta Computer classindaki fonskiyonlarin implementationlari vardir
 */

#include "Computer.h"

//Bu constructor maindeki classlarin objelerini alip yeni olusturulan objelere atiyor
Computer ::Computer(CPU myCPU,CPUProgram myCPUProgram,Memory myMemory,const int option)     
         :computerCPU(option),computerCPUProgram(option),computerMemory(option),option(option)
{
    myCPU.setReg(0);
    setCPU(myCPU);
    setCPUProgram(myCPUProgram);
    myMemory.setMemoryZero(0);
    setMemory(myMemory);
    
}


Computer ::  Computer(const int option) 
         : computerCPU(option),computerCPUProgram(option),computerMemory(option),option(option)
       
{
     
}

//dosyadan okuyup butun instructionlari teker teker hlt gorene kadar calistiryor
void Computer::execute()
{
   
     if(computerCPUProgram.checkErrors()!=-1)
        {
             while(!computerCPU.halted())
         { 
            
            string instruction = computerCPUProgram.getLine(computerCPU.getPC()-1);
            computerCPU.execute(instruction,computerMemory);
            //computerCPU.print();
            
          }
  
        }
}