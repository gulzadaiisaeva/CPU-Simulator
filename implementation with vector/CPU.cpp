/* 
 * File:   CPU.cpp
 * Author: Gulzada IISAEVA - 131044085
 * 
 * Bu classta CPU classindaki fonskiyonlarin implementationlari vardir
 */

#include "CPU.h"


CPU::CPU(const int opt) 
{
    setReg(0);
    setOption(opt);
}


void CPU::print ()const { //registr degerlerini print ediyor
 	for (int i = 0; i < 5; ++i)
 	{
 		cout << "Reg ["<<i+1<< "] -> "<<getReg(i)<< endl;
 	}

 }

void CPU::setReg(const int var)
{
     for (int i = 0; i < 5; ++i) //registrlarin hepsine 0 atiyor
    {
    	arrReg[i]=0;
    }
}
int CPU::isANumber(const string str) const //Stringin sayi olup olmadigi kontrol ediyor
{
    for (int i=0; i<str.size(); i++)
  {
    if((str[i] <'0') || (str[i] > '9'))
    return -1;
  }
    return 1;
}
int CPU::toInteger(string str) //Stringi integere cevirir
{
    int num=0; 
    int len=str.size();
    for (int i = 0; i < len; ++i)
    {
     num=num*10+(str[i]-'0');
    }

    return num;
}
string CPU::toLower(string substring) const /*Verilen stringleri kucuk harfe ceviriyor*/
{
    for (int j=0; j < substring.size(); j++)  //hepsini kucuk harfa degistirmek
  {
    if(substring[j] >= 'A' && substring[j] <= 'Z')
    substring[j] += 'a'- 'A';
  }
    return substring;
}
int CPU::indexOfReg(const string str)const//sring i alip arrayin indexini dondurur
{
    int indOfR1=0,indOfR2=1,indOfR3=2,indOfR4=3,indOfR5=4;
    if(str=="r1")
    {
        return indOfR1;
    }
    else if(str=="r2")
    {
        return indOfR2;
    }
    else if(str=="r3")
    {
        return indOfR3;
    }
     else if(str=="r4")
    {
        return indOfR4;
    }
     else if(str=="r5")
    {
        return indOfR5;
    }
}
void CPU::movRegReg(const int reg1,const int reg2) //MOV reg reg gibi instr calistirir
 {
    arrReg[reg2]=arrReg[reg1];
 }
void CPU::movRegConst(const int reg1, const int num)//MOV reg const instr calistir;
 {
     arrReg[reg1]=num;
 }

void CPU::addRegReg(const int reg1,const int reg2)//ADD reg reg gibi instr calistirir
{
    arrReg[reg1]+=arrReg[reg2];
}


void CPU::addRegConst(const int reg1, const int num)//ADD reg const gibi instr calistirir
{
    arrReg[reg1]+=num;
}
void CPU:: subRegReg(const int reg1,const int reg2)//SUB reg reg gibi instr calistirir
{
    arrReg[reg1]=arrReg[reg1]-arrReg[reg2];
}
void CPU::subRegConst(const int reg1, const int num)//SUB reg const gibi instr calistirir*/
{
    arrReg[reg1]=arrReg[reg1]-num;
}
 int CPU:: halted() const
 {
     
     if (getFlag()==0)
         return 0;
     else
         return 1;
 }

//adresler icin instr islemler
void CPU::MovRegAd(string str, Memory& myMem,int index) //verilen registri memory  adrese atiyor
 {
   if (str=="r1")
  {
       
       myMem.setMem(index,getReg(0));
       
  }
  else if (str=="r2")
  {
      
       myMem.setMem(index,getReg(1));
       
  }
   else if (str=="r3")
  {
      
      myMem.setMem(index,getReg(2));
       
  }
   else if (str=="r4")
  {
      
       myMem.setMem(index,getReg(3));
      
  }
   else if (str=="r5")
  {
     
       myMem.setMem(index,getReg(4));
       
  }
}
void CPU::MovAdReg  (string str, Memory& myMem,int index)//verilen adresteki degeri registr e atiyor
{
   if (str=="r1")
  {
       arrReg[0]=myMem.getMem(index);
      
       
  }
  else if (str=="r2")
  {
      
       arrReg[1]=myMem.getMem(index);
       
  }
   else if (str=="r3")
  {
      
      arrReg[2]=myMem.getMem(index);
       
  }
   else if (str=="r4")
  {
      
      arrReg[3]=myMem.getMem(index);
      
  }
   else if (str=="r5")
  {
     
       arrReg[4]=myMem.getMem(index);
       
  } 
}

void CPU::MovAdConst (Memory& myMem,int constNum, int index)//verilen const degeri memory adrese atiyor
{
    myMem.setMem(index,constNum);
}
void CPU::AddRegAdr (string str, Memory& myMem, int index)// verilen registr ile memorydeki degeri toplayip registr e atiyor
{
    if (str=="r1")
  {
    arrReg[0]+=myMem.getMem(index);
  }
  else if (str=="r2")
  {
    arrReg[1]+=myMem.getMem(index);
  }
   else if (str=="r3")
  {
    arrReg[2]+=myMem.getMem(index);
  }
   else if (str=="r4")
  {
    arrReg[3]+=myMem.getMem(index);
  }
   else if (str=="r5")
  {
   arrReg[4]+=myMem.getMem(index);
  }
}
 void CPU::SubRegAdr (string str, Memory& myMem, int index) // verilen registr dan den memorydeki degeri cikartip registr e atiyor
 {
    
    if (str=="r1")
  {
    arrReg[0]-=myMem.getMem(index);
  }
  else if (str=="r2")
  {
    arrReg[1]-=myMem.getMem(index);
  }
   else if (str=="r3")
  {
    arrReg[2]-=myMem.getMem(index);
  }
   else if (str=="r4")
  {
    arrReg[3]-=myMem.getMem(index);
  }
   else if (str=="r5")
  {
   arrReg[4]-=myMem.getMem(index);
  } 
 }
 
void CPU::execute(string str,Memory& myMem)
 {
   
     size_t found = str.find(',');  // , varsa
     int silInd=str.find_first_not_of(' ', found+1); //2.instr sonraki boslugu silme
     str.erase(found+1,(silInd-found)-1);
 
     str=toLower(str);
     
     
     if (found!=-1)
     {
         if (option==1)
         {
             cout << str << endl;
         }    
          if (option==2)
         {
             cout << str << endl;
         }
        string substr1=str.substr(0,3); //ilk 3harfli instr (mov)
        //cout << "1 ->"<<substr1 << endl;
        int ind=str.find_first_not_of(' ',4);//mov dan sonraki ilk harf
        string substr2=str.substr(ind,found-ind); //movdan sonraki instr (R1)
        //cout << "2 ->"<<substr2 <<endl;
        int indexOfArr=indexOfReg(substr2); //eger substr2 r1 ise 0, r2 ise 1 v.s dondurur
        
        int index1=str.find_first_not_of(' ',found+1); // , R1
        int index1x1=str.find_first_of(' ',index1);
        string substr3=str.substr(index1,index1x1-index1); // virgulden sonraki instr
        
        //cout << "3 ->"<<substr3 << endl;
     
         if (substr1=="mov")
         {  
             
             size_t sharp1 = substr2.find('#');  // substr2 de # varsa
             size_t sharp2 = substr3.find('#');  // substr3 de # varsa
             
             if (sharp1==-1 && sharp2==-1) //Normal MOV R1 , R2 gelirse
             {
                   if(isANumber(substr3)==1) // substr3 sayi ise
                 {
                     int num=toInteger(substr3);
                     movRegConst(indexOfArr, num);  //R1 , 100 gibi 
                 }
                  else
                 {
                    int indexOfArr2=indexOfReg(substr3); ////eger substr3 r1 ise 0, r2 ise 1 v.s dondurur
                    movRegReg(indexOfArr,indexOfArr2); //MOV R1, R2 gibi
                 }   
             }
             else  //# varsa 
             {
                 
                 if (sharp2!=-1) //substr3 te # varsa
                 {
                     substr3.erase(0,1); //#  siliyor
                     int num=toInteger(substr3);
                     MovRegAd(substr2,myMem,num); //MOV R1 -> #20 
                 }
                 else  
                 {
                     substr2.erase(0,1); //substr2ni # siliyor 
                     int indexofAdrr=toInteger(substr2); // substr2 integere cevir
                     if (isANumber(substr3)==1) //substr sayi ise MOV #20 , 100
                     {
                         int num=toInteger(substr3);
                         MovAdConst(myMem,num,indexofAdrr); //MOV #20 , 100
                     }
                     else
                     {
                         MovAdReg(substr3,myMem,indexofAdrr); //MOV #20 , R1
                     }
                    
                 }
             }
           
             setPC(getPC()+1);
         }
         else if(substr1=="add")
         {
             size_t sharp = substr3.find('#');  // # varsa
             if (sharp==-1)
             {
                   if(isANumber(substr3)==1) 
                {
                  int num=toInteger(substr3);
                  addRegConst(indexOfArr, num);
                }
                else
                {
                  int indexOfArr2=indexOfReg(substr3);
                  addRegReg(indexOfArr,indexOfArr2);
                }
             }
             else
             {
                 substr3.erase(0,1);
                 int num=toInteger(substr3);
                 AddRegAdr(substr2,myMem,num);
             }
           
             setPC(getPC()+1);
         }
         else if(substr1=="sub")
         {
             
             size_t sharp = substr3.find('#');  // # varsa
             if (sharp==-1)
             {
                 
                if(isANumber(substr3)==1)
               {
                   
                 int num=toInteger(substr3);
                 subRegConst(indexOfArr, num);
               }
               else
               {
                    
                 int indexOfArr2=indexOfReg(substr3);
                 subRegReg(indexOfArr,indexOfArr2);
               }
             }
             else
             {
                 substr3.erase(0,1);
                 int num=toInteger(substr3);
                 SubRegAdr(substr2,myMem,num);
             }
             setPC(getPC()+1);
         }
        else if(substr1=="jmp")
         {
           
            int indexOfArr=indexOfReg(substr2);
            if(getReg(indexOfArr)==0)
            {
               int num=toInteger(substr3);
               setPC(num);
              
            }
            else
            {
                setPC(getPC()+1);
            }
         }
        else if(substr1=="jpn")
         {
           
            int indexOfArr=indexOfReg(substr2);
            if(getReg(indexOfArr)<=0)
            {
               int num=toInteger(substr3);
               setPC(num);
              
            }
            else
            {
                setPC(getPC()+1);
            }
         }
        
         if (option==1)
         {
             print();
         }
          if (option==2)
         {
             print();
             myMem.printAll();
         }
        
     }
     else // eger virgul yoksa PRN , JMP 6 gibi
     {
          if (option==1)
         {
             cout << str << endl;
         }
          
           if (option==2)
         {
             cout << str << endl;
         }
          
          string substr1=str.substr(0,3); //PRN ilk 3 instr
          int index1=str.find_first_of(' ',4);
          string substr2=str.substr(4,index1-4);
         if (substr1=="prn")
         {
             size_t sharp = substr2.find('#');  // # varsa
             if (sharp==-1)
             {
                    if(isANumber(substr2)==1)
                 {
                        cout << "PRN const -> "<<substr2<< endl;

                 }
                 else
                 {
                   int indexOfArr=indexOfReg(substr2);
                   cout << "PRN "<< substr2 <<"-> "<<getReg(indexOfArr)<< endl;
                 }
             } 
              else
                 {
                       substr2.erase(0,1);
                       int num=toInteger(substr2);
                       cout << "PRN #"<<substr2<< " -> "<<myMem.getMem(num)<< endl;
                 }
             
               setPC(getPC()+1);
         }
         else if(substr1=="jmp")
         {
          
             if(isANumber(substr2)==1)
                {
                    int num=toInteger(substr2);
                    setPC(num);
                }
         }
         else if(substr1=="hlt")
         {
             print();
             myMem.printAll();
             setFlag(-1);
         }
           if (option==1)
         {
             print();
         }
           if (option==2)
         {
             print();
             myMem.printAll();
         }
     }
    
 }