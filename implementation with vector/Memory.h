/* 
 * File:   Memory.h
 * Author: Gulzada IISAEVA - 131044085
 * 
 *  Belli  bir kurallari olan programlama dilinin bilgilerinin bulundugu text
dosyasi vardir.Dosyadan okundugu bilgilerin o dilin kurallarina uygun  kodu
yazilip verilen text dosyasi bi program gibi calismali. Programda 
5 tane regist var. Dosyadan instructionlari okuyup
bu registr uzerinden OOP kullanilarak islemler yapilacak                        */
/*Bu classin icinde unsigned int [50] tanimlayip gerekli setter getterler
 yazili*/

#ifndef MEMORY_H
#define	MEMORY_H


#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Memory {
public:
    Memory(const int option);
    void setMem(const int index, const int value);
    void setMemoryZero(const int val);
    int getMem(const int index) const {return myMemAddress[index];};
    void printAll() const ;
    
    
private:
    unsigned int myMemAddress[50];  //memory adres
    
};


#endif	/* MEMORY_H */


