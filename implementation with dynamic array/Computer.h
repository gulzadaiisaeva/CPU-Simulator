/* 
 * File:   Computer.h
 * Author: Gulzada IISAEVA - 131044085
 * 
Belli  bir kurallari olan programlama dilinin bilgilerinin bulundugu text
dosyasi vardir.Dosyadan okundugu bilgilerin o dilin kurallarina uygun  kodu
yazilip verilen text dosyasi bi program gibi calismali. Programda 
5 tane registr ve unsigned int [50] var. Dosyadan instructionlari okuyup
bu registr ve memory uzerinden OOP kullanilarak islemler yapilacak 
 *   
/*Bu class onceden olusturulan CPUProgramDyn CPU Memory obejelerini alip kendi 
 * olusturdugu objlere atiyor ve uzerinden  islemleri yapiyor */
 


#ifndef COMPUTER_H
#define	COMPUTER_H
#include<iostream>
#include<string>
#include<fstream>

#include "Memory.h"
#include "CPU.h"
#include "CPUProgram.h"


using namespace std;

class Computer {
public:
    //Bu constructor maindeki classlarin objelerini alip yeni olusturulan objelere atiyor
    Computer(CPU myCPU,CPUProgram myCPUProgram,Memory myMemory,const int option);
    Computer(const int option);
   
    CPU getCPU() {return computerCPU;};
    CPUProgram getCPUProgram() {return computerCPUProgram;};
    Memory getMemory() {return computerMemory;};
    
    void setCPU(CPU myCPU) {computerCPU=myCPU;};
    void setCPUProgram (CPUProgram myCPUProgram) {computerCPUProgram=myCPUProgram;};
    void setMemory(Memory myMemory) {computerMemory=myMemory;};

    //dosyadan okuyup butun instructionlari teker teker hlt gorene kadar calistiryor
    void execute();
private:
    CPU computerCPU;
    CPUProgram computerCPUProgram;
    Memory computerMemory;
    int option;
};

#endif	/* COMPUTER_H */

