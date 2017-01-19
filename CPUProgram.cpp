/* 
 * File:   CPUProgram.cpp
 * Author: Gulzada IISAEVA - 131044085
 * 
 * Bu classta CPUProgram classindaki fonskiyonlarin implementationlari vardir
 */
/*Hocam moodleda CPUProgram classinin operatorleri icin
 * sorular formunda hatalari buldugunuzda error mesaji verip islemleri iptal edin
 ama program devam etsin dediginizden dolayi hata buldugunda error mesaji verip alt 
 satira geciyor */

#include "CPUProgram.h"


// Operator[] that takes an integer
// and works like the getLine function. It returns the program line as a string. 
string& CPUProgram::operator[](int lineNumber)
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

/*Operator+ that takes a CPUProgram and an instruction line as a string. It returns a new
CPUProgram that has the original CPUProgram with appended last line from the parameter
string.*/
CPUProgram CPUProgram::operator +( const string instrLine) const
{
    CPUProgram newProg;
    newProg=*this;
    newProg.str.push_back(instrLine);
    newProg.setLineSize(newProg.size()+1);
    return newProg;
}
//Operator+= that takes an instruction line as a string and appends the instruction to the end of
//the program.
 CPUProgram& CPUProgram::operator +=( const string instrLine)
 {   if (instrLine.empty() )
    {
       cout << "You have entered the wrong instruction which you cannot append,"
               " so the last instruction is the same " ;
        return *this;
    }
    else
    {
     str.push_back(instrLine);
     setLineSize(str.size());
      return *this;
    } 
    
 }
//Operator+ that takes two programs and returns a new program that appends the second
//programs to the first one 
CPUProgram CPUProgram::operator +( const CPUProgram& myCPUProgram2)
 {
     CPUProgram Obje;
     Obje.str=str;
     Obje.str.insert(Obje.str.end(), myCPUProgram2.str.begin(),myCPUProgram2.str.end());
     Obje.setLineSize(Obje.str.size());
     
     return Obje;
}
//All comparison operators ==, !=, <, >=, etc. All comparison operators compare the number of
//lines of the programs.
 bool CPUProgram::operator ==(const CPUProgram& myCPUProgram2) const
 {
     return (size() == myCPUProgram2.size());
 }
 bool CPUProgram::operator !=(const CPUProgram& myCPUProgram2) const
 {
     return (size() != myCPUProgram2.size());
 }
 bool CPUProgram::operator <(const CPUProgram& myCPUProgram2) const
 {
     return (size() < myCPUProgram2.size());
 }
bool CPUProgram::operator >(const CPUProgram& myCPUProgram2) const
{
    return (size() > myCPUProgram2.size());
}
bool CPUProgram::operator <=(const CPUProgram& myCPUProgram2) const
{
    return (size() <= myCPUProgram2.size());
}
bool CPUProgram::operator >=(const CPUProgram& myCPUProgram2) const
{
    return (size() >= myCPUProgram2.size());
}

//Post decrement operator - - that delete the last line of the program.
CPUProgram CPUProgram::operator --()
{
    str.pop_back();
    setLineSize(str.size()-1);
    
    return *this;
}
//pre decrement operator - - that delete the last line of the program.
CPUProgram CPUProgram::operator --(int ignore)
{
    CPUProgram obje;
    obje=*this;
    str.pop_back();
    setLineSize(str.size()-1);
    return obje;
}

//Function call operator() that takes two integers and returns a new program that contains the
//instructions between the given integers.
CPUProgram CPUProgram::operator ()(int index1, int index2)
{
    CPUProgram newProg;
    if (index1<0 || index2 >= size() || index1>=index2 || index2 <0 )
    {
        cout << "You have entered the wrong index!The min index"
              " is 0, the max is "<<size()-1;
        newProg.str.push_back(". So this program doesnt contain the instructions ");
        newProg.setLineSize(newProg.str.size());
        return newProg;
    }
    else
    {
            for (int i=index1;i <= index2; i++)
            {
                newProg.str.push_back(getLine(i));

            }
            newProg.setLineSize(newProg.str.size());
            return  newProg;
    }

}

//Operator that prints the program
ostream& operator <<(ostream& output,const CPUProgram& myCPUProgram)
{
 for (int i = 0; i < myCPUProgram.size(); ++i)  //instr oldugu stringi print etme
    {
    output << myCPUProgram.str[i] << endl;
    }   
 return output;
}
void CPUProgram :: ReadFile (const char filename[]) //verilen input dosyasindan stringe okuyor
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
      	str.push_back(temp);
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
  }
  else cout << "Unable to open file"<< endl;
  
}

string CPUProgram::getLine(int lineNumber) const{ //girilen sayiya gore stringin satirini donduruyor
    return str[lineNumber];
}


void CPUProgram::printStr() const{
    for (int i = 0; i < size(); ++i)  //instr oldugu stringi print etme
    {
    cout << str[i] << endl;
    }
}
string CPUProgram::toLower(string substring) const /*Verilen stringleri kucuk harfe ceviriyor*/
{
    for (int j=0; j < substring.size(); j++)  //hepsini kucuk harfa degistirmek
  {
    if(substring[j] >= 'A' && substring[j] <= 'Z')
    substring[j] += 'a'- 'A';
  }
    return substring;
}
int CPUProgram::isANumber(string str){  //stringin sayi olup olmadigini control ediyor
    
  for (int i=0; i<str.size(); i++)
  {
    if((str[i] <'0') || (str[i] > '9'))
    return -1;
  }
    return 1;
}
int CPUProgram::toInteger(string str) //Stringi integere cevirir
{
    int num=0; 
    int len=str.size();
    for (int i = 0; i < len; ++i)
    {
     num=num*10+(str[i]-'0');
    }

    return num;
}

int  CPUProgram::isMemAddress(string mem)
{
    string newStr=mem;
    newStr.erase(0,1);
    int newInt=toInteger(newStr);

    if (newInt>50){
        return -1;
    }
    return 1;
}
int CPUProgram::checkErrors() //dosyadaki instrlarin dogru olup olmadigini kontrol ediyor
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