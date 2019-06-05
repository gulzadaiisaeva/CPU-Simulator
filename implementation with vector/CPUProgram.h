/* 
 * File:   CPUProgram.h
 * Author: Gulzada IISAEVA - 131044085
 * 
Belli  bir kurallari olan programlama dilinin bilgilerinin bulundugu text
dosyasi vardir.Dosyadan okundugu bilgilerin o dilin kurallarina uygun  kodu
yazilip verilen text dosyasi bi program gibi calismali. Programda 
5 tane registr ve unsigned int [50] var. Dosyadan instructionlari okuyup
bu registr ve memory uzerinden OOP kullanilarak islemler yapilacak                      */
/*Bu classin icinde dosyadan veriyi okuyup , kurallara uygun mu onu kontrol ederek
 satir sayisini buluyor ve stringe atiyor.Getline da verilen PC countera gore
 satiri donduruyor*/
 
 //Bu odevde CPUProgram classi icin gerekli operatorleri implement ettim

#ifndef CPUProgram_H
#define	CPUProgram_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

class CPUProgram {
public:
    CPUProgram () {};
    CPUProgram(const int option) { };
   
    int flagFile=0;
   
    void setLineSize(const int var) { lineSize=var;}; // stringin satir sayisini set ediyor
    void ReadFile (const char filename[]);  //dosyadan stringe okuma
    int size() const {return lineSize;} ;
    void printStr() const;
    string getLine(const int lineNumber) const;
    string toLower(string substring) const; /*Verilen stringleri kucuk harfe ceviriyor*/
    int checkErrors(); //dosyadaki instrlarin dogru olup olmadigini kontrol ediyor

    string& operator[]( int lineNumber); // Operator[] that takes an integer
    // and works like the getLine function. It returns the program line as a string. 
    
    CPUProgram operator +(string instrLine) const;
    CPUProgram& operator +=( string instrLine);
    
    CPUProgram operator +( const CPUProgram& myCPUProgram2);
    bool operator ==(const CPUProgram& myCPUProgram2) const;
    bool operator !=(const CPUProgram& myCPUProgram2) const;
    bool operator <(const CPUProgram& myCPUProgram2) const;
    bool operator >(const CPUProgram& myCPUProgram2) const;
    bool operator <=(const CPUProgram& myCPUProgram2) const;
    bool operator >=(const CPUProgram& myCPUProgram2) const;
    CPUProgram operator --();
    CPUProgram operator --(int ignore);
    CPUProgram operator ()(int index1, int index2);
    
    friend ostream& operator <<(ostream& output,const CPUProgram& myCPUProgram);
    
private:
      vector <string> str; //islem yapilacak string
     int lineSize;
     int isANumber(const string str); //Stringin sayi olup olmadigi kontrol ediyor
     int toInteger(const string str); //Stringi integere cevirir
     int isMemAddress(string mem);
  
};

#endif	/* CPUProgram_H */

