/* 
 * File:   CPUProgramDyn.h
 * Author: Gulzada IISAEVA - 131044085
 * 
Belli  bir kurallari olan programlama dilinin bilgilerinin bulundugu text
dosyasi vardir.Dosyadan okundugu bilgilerin o dilin kurallarina uygun  kodu
yazilip verilen text dosyasi bi program gibi calismali. Programda 
5 tane registr ve unsigned int [50] var. Dosyadan instructionlari okuyup
bu registr ve memory uzerinden OOP kullanilarak islemler yapilacak                      */
/*Bu classin icinde dosyadan veriyi okuyup , kurallara uygun mu onu kontrol ederek
 satir sayisini buluyor ve dynamic stringe atiyor.Getline da verilen PC countera gore
 satiri donduruyor*/
 
 //Bu odevde CPUProgramDyn classi icin gerekli operatorleri implement ettim
//Pointer var oludugundan big three kullandim

#ifndef CPUProgramDyn_H
#define	CPUProgramDyn_H


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

namespace CPUProgramDynamic {
    
class CPUProgramDyn {
public:
    CPUProgramDyn ():lineSize(0),str(NULL),option(-1){};
    CPUProgramDyn(const int opt) :lineSize(0),str(NULL),option(opt){};
    CPUProgramDyn (const CPUProgramDyn& copyConstructor ); //copy constructor
    CPUProgramDyn& operator = (const CPUProgramDyn myCPUProgramDyn2);
    ~CPUProgramDyn ();
   
    int flagFile=0;
   
    void setLineSize(const int var) { lineSize=var;}; // stringin satir sayisini set ediyor
    void ReadFile (const char filename[]);  //dosyadan stringe okuma
    int size() const {return lineSize;} ;
    void printStr() const;
    string getLine(const int lineNumber) const;
    string toLower(string substring) const; /*Verilen stringleri kucuk harfe ceviriyor*/
    int checkErrors(); //dosyadaki instrlarin dogru olup olmadigini kontrol ediyor

    string& operator[]( const int lineNumber); // Operator[] that takes an integer
    // and works like the getLine function. It returns the program line as a string. 
    
    CPUProgramDyn operator +(const string instrLine) const;
    CPUProgramDyn& operator +=(const string instrLine);
    
    CPUProgramDyn operator +( const CPUProgramDyn& myCPUProgramDyn2);
    bool operator ==(const CPUProgramDyn& myCPUProgramDyn2) const;
    bool operator !=(const CPUProgramDyn& myCPUProgramDyn2) const;
    bool operator <(const CPUProgramDyn& myCPUProgramDyn2) const;
    bool operator >(const CPUProgramDyn& myCPUProgramDyn2) const;
    bool operator <=(const CPUProgramDyn& myCPUProgramDyn2) const;
    bool operator >=(const CPUProgramDyn& myCPUProgramDyn2) const;
    CPUProgramDyn operator --();
    CPUProgramDyn operator --(int ignore);
    CPUProgramDyn operator ()(const int index1, const int index2);
    
    friend ostream& operator <<(ostream& output,const CPUProgramDyn& myCPUProgramDyn);
    
private:
     string *str;
     int lineSize;
     int option;
     int isANumber(const string str); //Stringin sayi olup olmadigi kontrol ediyor
     int toInteger(const string str); //Stringi integere cevirir
     int isMemAddress(string mem);
  
};
}
#endif	/* CPUProgramDyn_H */

