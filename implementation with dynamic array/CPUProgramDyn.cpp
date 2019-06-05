/* 
 * File:   CPUProgramDyn.cpp
 * Author: Gulzada IISAEVA - 131044085
 * 
 * Bu classta CPUProgramDyn classindaki fonskiyonlarin implementationlari vardir
 */
/*Hocam moodleda CPUProgramDyn classinin operatorleri icin
 * sorular formunda hatalari buldugunuzda error mesaji verip islemleri iptal edin
 ama program devam etsin dediginizden dolayi hata buldugunda error mesaji verip alt 
 satira geciyor */

#include "CPUProgramDyn.h"

namespace CPUProgramDynamic {
//destructor
CPUProgramDyn::~CPUProgramDyn() {
    delete [] str;
    str=NULL;
}

//copy constructor
CPUProgramDyn:: CPUProgramDyn (const CPUProgramDyn& copyConstructor )
    :lineSize(copyConstructor.lineSize),option(copyConstructor.option)
{  
    str= new string [lineSize];
    for(int i=0; i< lineSize; i++)
    {
        str[i]=copyConstructor.str[i];
    }
}
//asssign operator
CPUProgramDyn& CPUProgramDyn::operator = (const CPUProgramDyn myCPUProgramDyn2)
{
    if (&myCPUProgramDyn2 !=this)
    {
        lineSize=myCPUProgramDyn2.lineSize;
        option=myCPUProgramDyn2.option;
        str= new string [myCPUProgramDyn2.lineSize];
        for(int i=0; i< lineSize; i++)
        {
            str[i]=myCPUProgramDyn2.str[i];
        } 
    }
    return *this;
}
void CPUProgramDyn :: ReadFile (const char filename[]) //verilen input dosyasindan stringe okuyor
{
    string bosluk=" ";
    setLineSize(0);
  fstream InputStream;  //dosya acma
  string temp;
  InputStream.open(filename);   //hangi dosyadan okuyacak
  if (InputStream.is_open())
  {
        while (getline (InputStream,temp))//dosyadi her line i alip FromTxt ye atiyor
      {
        setLineSize(size()+1);
      }
  	InputStream.close();
        ///////////////////////////////////////////////////////
        /////////New code///////////////////////////////////
        InputStream.open(filename);
        str= new string[lineSize];
        setLineSize(0);
        while (getline (InputStream,temp))//dosyadi her line i alip FromTxt ye atiyor
      {
          str[size()]=temp;
      	size_t found = str[size()].find(';');  //; sonrasin silme
  	if (found!=-1)
        {
        int index= str[size()].find_first_of(";");
        str[size()].erase(index);
        }
        str[size()].append(bosluk);
        setLineSize(size()+1);
      }
  	InputStream.close();
         ///////////////////////////////////////////////////////
  }
  else cout << "Unable to open file"<< endl;
  
}

void CPUProgramDyn::printStr() const{
    for (int i = 0; i < size(); ++i)  //instr oldugu stringi print etme
    {
    cout << str[i] << endl;
    }
}



string CPUProgramDyn::getLine(int lineNumber) const{ //girilen sayiya gore stringin satirini donduruyor
    return str[lineNumber];
}


string CPUProgramDyn::toLower(string substring) const /*Verilen stringleri kucuk harfe ceviriyor*/
{
    for (int j=0; j < substring.size(); j++)  //hepsini kucuk harfa degistirmek
  {
    if(substring[j] >= 'A' && substring[j] <= 'Z')
    substring[j] += 'a'- 'A';
  }
    return substring;
}
int CPUProgramDyn::isANumber(string str){  //stringin sayi olup olmadigini control ediyor
    
  for (int i=0; i<str.size(); i++)
  {
    if((str[i] <'0') || (str[i] > '9'))
    return -1;
  }
    return 1;
}
int CPUProgramDyn::toInteger(string str) //Stringi integere cevirir
{
    int num=0; 
    int len=str.size();
    for (int i = 0; i < len; ++i)
    {
     num=num*10+(str[i]-'0');
    }

    return num;
}

int  CPUProgramDyn::isMemAddress(string mem)
{
    string newStr=mem;
    newStr.erase(0,1);
    int newInt=toInteger(newStr);

    if (newInt>50){
        return -1;
    }
    return 1;
}
int CPUProgramDyn::checkErrors() //dosyadaki instrlarin dogru olup olmadigini kontrol ediyor
 {  
        string bosluk=" ";
        string virgul=",";
        int forCheck=0, flag1=0,flag2=0,flag3=0,flag4=0,checkMemInstr2=0,checkMemInstr3=0,flagIsAdr=0,jmpcheck=0;
        
     for (int i = 0; i < size(); i++) 
     {
        int ind1=getLine(i).find_first_not_of(' ',0); //bosluk olmayana kadar
        int ind2=getLine(i).find_first_of(' ',ind1); //bosluga kadar
        string substr1=getLine(i).substr(ind1,ind2-ind1);  //ilk 3 harfli instr (mov)
        substr1=toLower(substr1);
        size_t found = getLine(i).find(',');  // , varsa
       
  	if (found!=-1)
        {
        
        if (substr1=="mov" || substr1=="add" || substr1=="sub" || substr1=="jmp"  || substr1=="jpn") 
        {
           int ind3=getLine(i).find_first_not_of(' ',ind2); //movdan sonra not ' '
           int ind4=getLine(i).find_first_of(',',ind3);  //, e kadar
           string substr=getLine(i).substr(ind3,ind4-ind3); //mov dan sonra , e kadar
           substr.append(bosluk);
           int ind31=substr.find_first_of(' ',0);//ikinci instr
           string substr2=substr.substr(0,ind31);
           substr2=toLower(substr2);
          
           
           size_t sharpInstr2 = substr2.find('#') ; //eger # harfi varsa
           
     	   if (sharpInstr2 != -1)
           {
           checkMemInstr2=isMemAddress(substr2); //#20 diye kontrol ediyor
          	if (checkMemInstr2==-1)
             {
             	cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
              	forCheck=-1;
                flagIsAdr!=-1;
             }  
                int check=substr.find_first_not_of(' ',ind31); //ikinci instr sonra herhangi harf varmi
                if (check!=-1 && flagIsAdr!=-1)
                {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1; 
                }
             
           }
           else
           {
           int check=substr.find_first_not_of(' ',ind31); //ikinci instr sonra herhangi harf varmi
           
                if (substr2!="r1" && substr2!="r2" && substr2!="r3" && substr2!="r4" && substr2!="r5")
                 {
                     cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                     flag1=-1;
                     forCheck=-1;      
                 }
                if (check!=-1 && flag1!=-1)
                {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1; 
                }
           }
           // , sonra
           int ind5=getLine(i).find_first_not_of(' ',ind4+1); //bosluk olmayana
           int ind6=getLine(i).find_first_of(' ',ind5); //bosluk olana
           string substr3=getLine(i).substr(ind5,ind6-ind5);  //, den sonraki kelime
           substr3=toLower(substr3);
           
           size_t sharpInstr3 = substr3.find('#') ; //eger # harfi varsa
          
           if (sharpInstr3 != -1)
           {
           checkMemInstr3=isMemAddress(substr3); //#20 diye kontrol ediyor
          	if (checkMemInstr3==-1)
             {
             	cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
              	forCheck=-1;

             }
           }
     	   else
           {
                          
                int check2=getLine(i).find_first_not_of(' ',ind6); // 3.instr sonra harf varsa hata ver

                if (check2!=-1 && flag1!=-1)
                {
                   cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                   forCheck=-1;

                }
                if (isANumber(substr3)==-1 && flag1!=-1)
                {
                    if(substr3!="r1" && substr3!="r2" && substr3!="r3" && substr3!="r4" && substr3!="r5")
                    {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1;

                    }
                }
           }

           if (substr1=="jmp"  || substr1=="jpn")
           {

                
               if(isANumber(substr3)==-1 && flag1!=-1)
               {
                  {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1;
                    flag4=-1;
               
                  } 
               }
               else
               {
                   int num = toInteger(substr3);
                   if(num > size() && flag1!=-1 )
                    {
                     
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1;
                    }
               }
           }
 
           str[i]=substr1+bosluk+substr2+virgul+substr3+bosluk;
        }
        else
        {
            
            cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
            forCheck=-1;
        }

        }
        else
        {
            if ( substr1=="prn" ) 
            {
                int ind3=getLine(i).find_first_not_of(' ',ind2); //jmp dan sonra not ' '
                int ind4=getLine(i).find_first_of(' ',ind3); //bosluga kadar
                string substr2=getLine(i).substr(ind3,ind4-ind3);
                substr2=toLower(substr2);
                
                size_t sharpInstr2 = substr2.find('#') ; //eger # harfi varsa

                if (sharpInstr2 != -1)
                {
                    checkMemInstr2=isMemAddress(substr2); //#20 diye kontrol ediyor
                    if (checkMemInstr2==-1)
            		 {
		             	cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
		              	forCheck=-1;
                                flagIsAdr==-1;
		             }
                }
              
                
                if (isANumber(substr2)!=1 && flagIsAdr!=-1)
                {
                    if(substr2!="r1" && substr2!="r2" && substr2!="r3" && substr2!="r4" && substr2!="r5"  )
                    {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    flag3=-1;
                    forCheck=-1;
                    
                    }
                }
                int ind5=getLine(i).find_first_not_of(' ',ind4);
                if(ind5!=-1 && flag3!=-1 && flagIsAdr!=-1)
                {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1;
                    
                }
                 str[i]=substr1+bosluk+substr2+bosluk;
            }
            else if ( substr1=="jmp"  ||  substr1=="jpn" ) 
            {
                int ind3=getLine(i).find_first_not_of(' ',ind2); //jmp dan sonra not ' '
                int ind4=getLine(i).find_first_of(' ',ind3); //bosluga kadar
                string substr2=getLine(i).substr(ind3,ind4-ind3);
                substr2=toLower(substr2);
                if (isANumber(substr2)!=1)
                {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction1" << endl;
                    flag4=-1;
                    forCheck=-1;
                       
                }
                else
                {
                    int num=toInteger(substr2);
                    if(num> size())
                    {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1;
                    flag4=-1;
                    }
                }
                int ind5=getLine(i).find_first_not_of(' ',ind4);
                if(ind5!=-1 && flag4!=-1)
                {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1;
                }
                str[i]=substr1+bosluk+substr2+bosluk;
            }
            else if (substr1=="hlt")
            {
                int ind3=getLine(i).find_first_not_of(' ',ind2); //hlt dan sonra not ' '
                if(ind3!=-1)
                {
                    cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                    forCheck=-1;
                }
                str[i]=substr1+bosluk;
            }
            else
            {
                cout << "In line "<< i+1 <<" :"<<getLine(i) <<" is " <<"Invalid instruction" << endl;
                forCheck=-1;
            }
            
        }
      }
        return forCheck;
 }
// Operator[] that takes an integer
// and works like the getLine function. It returns the program line as a string. 
string& CPUProgramDyn::operator[](const int lineNumber)
{
    if (lineNumber >= size() || lineNumber < 0)
    {
      cout << "You have entered the wrong index!The max index"
              " is "<<size()-1<<" , the last instruction is -> " ;
      return str[size()-1];
    }
    else
    {
      return str[lineNumber];
    }
}

/*Operator+ that takes a CPUProgramDyn and an instruction line as a string. It returns a new
CPUProgramDyn that has the original CPUProgramDyn with appended last line from the parameter
string.*/
CPUProgramDyn CPUProgramDyn::operator +( const string instrLine) const
{   
    CPUProgramDyn newProg(*this);
    delete [] newProg.str;
    newProg.str = new string[size()+1]; 
   
    for(int i=0 ; i < size();i++)
    {
        newProg.str[i]=str[i]; 
    }
    newProg.str[size()]=instrLine;
    
    newProg.setLineSize(newProg.size()+1);
    return newProg;
}

//Operator that prints the program
ostream& operator <<(ostream& output,const CPUProgramDyn& myCPUProgramDyn)
{
 for (int i = 0; i < myCPUProgramDyn.size(); ++i)  //instr oldugu stringi print etme
    {
    output << myCPUProgramDyn.str[i] << endl;
    }   
 return output;
}
//Operator+= that takes an instruction line as a string and appends the instruction to the end of
//the program.
 CPUProgramDyn& CPUProgramDyn::operator +=( const string instrLine)
 {   if (instrLine.empty() )
    {
       cout << "You have entered the wrong(empty) instruction which you cannot append,"
               " so the last instruction is the same " ;
        return *this;
    }
    else
    {
     string *temp= new string[size()+1];
      for(int i=0 ; i < size();i++)
    {
        temp[i]=str[i]; 
    }
     temp[size()]=instrLine;
     delete [] str;
     str= new string[size()+1];
     for(int i=0 ; i < size()+1;i++)
    {
        str[i]=temp[i]; 
    }
     delete [] temp;
     temp=NULL;
     setLineSize(size()+1);
      return *this;
    } 
    
 }
//Operator+ that takes two programs and returns a new program that appends the second
//programs to the first one 
CPUProgramDyn CPUProgramDyn::operator +( const CPUProgramDyn& myCPUProgramDyn2)
 {
    int newSize=size()+myCPUProgramDyn2.size();
     CPUProgramDyn Obje(*this);
     delete [] Obje.str;
     Obje.str=new string[newSize];
 
     for(int i=0 ; i < size();i++)
     {
         Obje.str[i]=str[i];
     }
     for(int i=size(); i < newSize;i++)
     {
         Obje.str[i]=myCPUProgramDyn2.str[i-size()];
     }
     Obje.setLineSize(size()+myCPUProgramDyn2.size());
     
     return Obje;
}
//All comparison operators ==, !=, <, >=, etc. All comparison operators compare the number of
//lines of the programs.
bool CPUProgramDyn::operator ==(const CPUProgramDyn& myCPUProgramDyn2) const
 {
     return (size() == myCPUProgramDyn2.size());
 }
 bool CPUProgramDyn::operator !=(const CPUProgramDyn& myCPUProgramDyn2) const
 {
     return (size() != myCPUProgramDyn2.size());
 }
 bool CPUProgramDyn::operator <(const CPUProgramDyn& myCPUProgramDyn2) const
 {
     return (size() < myCPUProgramDyn2.size());
 }
bool CPUProgramDyn::operator >(const CPUProgramDyn& myCPUProgramDyn2) const
{
    return (size() > myCPUProgramDyn2.size());
}
bool CPUProgramDyn::operator <=(const CPUProgramDyn& myCPUProgramDyn2) const
{
    return (size() <= myCPUProgramDyn2.size());
}
bool CPUProgramDyn::operator >=(const CPUProgramDyn& myCPUProgramDyn2) const
{
    return (size() >= myCPUProgramDyn2.size());
}

//Pre decrement operator - - that delete the last line of the program.
CPUProgramDyn CPUProgramDyn::operator --()
{
    string *temp=new string[size()-1];
    for(int i=0; i < size()-1;i++)
     {
         temp[i]=str[i];
     }
    delete [] str;
    str=new string[size()-1];
    for(int i=size(); i < size()-1;i++)
     {
         str[i]=temp[i];
     }
    delete [] temp;
    temp=NULL;
    setLineSize(size()-1);
    
    return *this;
}
//post decrement operator - - that delete the last line of the program.
CPUProgramDyn CPUProgramDyn::operator --(int ignore)
{
    CPUProgramDyn obje(*this);
 
    string *temp=new string[size()-1];
    for(int i=0; i < size()-1;i++)
     {
         temp[i]=str[i];
     }
    delete [] str;
    str=new string[size()-1];
    for(int i=size(); i < size()-1;i++)
     {
         str[i]=temp[i];
     }
    delete [] temp;
    temp=NULL;
    setLineSize(size()-1);
    return obje;
}

//Function call operator() that takes two integers and returns a new program that contains the
//instructions between the given integers.
CPUProgramDyn CPUProgramDyn::operator ()(const int index1, const int index2)
{
    CPUProgramDyn newProg;
    if (index1<0 || index2 >= size() || index1>=index2 || index2 <0 )
    {
        cout << "You have entered the wrong index!The min index"
              " is 0, the max is "<<size()-1;
        newProg.str=new string[1];
        newProg.str[0]=". So this program doesnt contain any instructions ";
        newProg.setLineSize(1);
        return newProg;
    }
    else
    {       
            int difference=index2-index1;
            newProg.str=new string[difference+1];
            for (int i=index1;i <= index2; i++)
            {
                
                newProg.str[i-index1]=getLine(i);

            }
           
            newProg.setLineSize(difference+1);
            return  newProg;
    }

}

}
