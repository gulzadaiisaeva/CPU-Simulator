/* 
 * File:   CPU.h
 * Author: Gulzada IISAEVA - 131044085
 * 
Belli  bir kurallari olan programlama dilinin bilgilerinin bulundugu text
dosyasi vardir.Dosyadan okundugu bilgilerin o dilin kurallarina uygun  kodu
yazilip verilen text dosyasi bi program gibi calismali. Programda 
5 tane registr ve unsigned int [50] var. Dosyadan instructionlari okuyup
bu registr ve memory uzerinden OOP kullanilarak islemler yapilacak   
/*CPUProgram classindan gelen stringi inceleyerek islemleri yapar*/
 

#ifndef CPU_H
#define	CPU_H

#include<iostream>
#include<string>
#include<fstream>

#include "Memory.h"

using namespace std;

class CPU {
public:
    
   
    CPU(const int opt); //butun registrlara 0 atiyor
    const int getPC()  const {return PC;}; //PC yi donduruyor
    void setPC(const int var) { PC=var;}; 
    void setOption(const int var) { option=var;};
    void setFlag(const int var){flag=var;};
    int getFlag()  const {return flag;};
    int getReg(const int var) const {return arrReg[var];};
    void setReg(const int var);
    void print () const; /*registr lari print  etme*/
    void printPC() const { cout << "PC is = " << PC << endl;};
    string toLower(string substring) const; /*Verilen stringleri kucuk harfe ceviriyor*/
    
    void movRegReg(const int reg1,const int reg2); //MOV reg reg gibi instr calistirir
    void movRegConst(const int reg1, const int num);//MOV reg const instr calistir
    void addRegReg(const int reg1,const int reg2);//ADD reg reg gibi instr calistirir
    void addRegConst(const int reg1, const int num);//ADD reg const gibi instr calistirir
    void subRegReg(const int reg1,const int reg2);//SUB reg reg gibi instr calistirir
    void subRegConst(const int reg1, const int num);//SUB reg const gibi instr calistirir
    
    void MovRegAd(string str, Memory& myMem,const int index); //verilen registri memory  adrese atiyor
    void MovAdReg(string str, Memory& myMem,const int index); //verilen adresteki degeri registr e atiyor
    void MovAdConst (Memory& myMem,int constNum,const  int index); //verilen const degeri memory adrese atiyor

    void AddRegAdr (string str, Memory& myMem, const int index);  // verilen registr ile memorydeki degeri toplayip registr e atiyor
    void SubRegAdr (string str, Memory& myMem, const int index); // verilen registr dan den memorydeki degeri cikartip registr e atiyor

    
    int halted() const ; //programi HLT gorunce sonlandiriyor
    void execute(string str, Memory& myMem); //gelen instructioni calisitiryor
    int toInteger(string str); //Stringi integere cevirir
    
    
    
private:
    int arrReg[5]; //5 tane registr tutan array
    int flag; //hata kontrolu
    int PC=1; //program counter
    int option;
    int isANumber(const string str) const; //Stringin sayi olup olmadigi kontrol ediyor
    int indexOfReg(const string str) const; //sring i alip arrayin indexini dondurur
    
};

#endif	/* CPU_H */

