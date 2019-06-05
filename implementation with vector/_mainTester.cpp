/* 
 * File:   main.cpp
 * Author: Gulzada IISAEVA - 131044085
 * 
 * /*Hocam moodleda CPUProgram classinin operatorleri icin
 * sorular formunda hatalari buldugunuzda error mesaji verip islemleri iptal edin
 ama program devam etsin dediginizden dolayi hata buldugunda error mesaji verip alt 
 satira geciyor
 myCPUProgam += "" i girilmesi hata olarak yazdim  */
 


#include <iostream>
#include <string>
#include <fstream>

using namespace std;


#include "requiredIncs.h"


int main(int argc, char** argv) {
    
    if (argc==3)
    {
        //////////////////////////////////////////////////////////////////////////
        //command line parameters
        const char* filename = argv[1];
        int option = atoi(argv[2]);
        //////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////
        //Testing class CPUProgram
        //op []
        CPUProgram myCPUProgram(option);
        myCPUProgram.ReadFile(filename);
      
        cout << myCPUProgram[0] << endl;
        cout << myCPUProgram[myCPUProgram.size() - 1] << endl;
        
        //op +
        cout << ((myCPUProgram + "MOV R1, #45")[myCPUProgram.size() - 1]) << endl;
        
        //op +=
        myCPUProgram += "MOV R2, #50";
        cout << myCPUProgram[myCPUProgram.size() - 1] << endl;
        
       
        //op + <<
        CPUProgram myOtherCPUProgram(option);
        myOtherCPUProgram.ReadFile(filename);
        cout << (myCPUProgram + myOtherCPUProgram) << endl;
        
        //op COMP --
        cout << (myCPUProgram == myOtherCPUProgram ? "DONE" : "FAIL") << endl;
        cout << (myCPUProgram <= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
        cout << (myCPUProgram >  myOtherCPUProgram ? "FAIL" : "DONE") << endl;
        
        --myOtherCPUProgram;
        cout << (myCPUProgram != myOtherCPUProgram ? "DONE" : "FAIL") << endl;
        cout << (myCPUProgram >= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
        cout << (myCPUProgram < myOtherCPUProgram ? "FAIL" : "DONE") << endl;
        
        //op ()
        cout << myCPUProgram(5, 10) << endl;
        //error check
        cout << myCPUProgram[myCPUProgram.size()] << endl;
       
        
        myCPUProgram += "";
        cout << myCPUProgram[myCPUProgram.size() - 1] << endl;

        //////////////////////////////////////////////////////////////////////////
        
       
    }
    else
    {
    cerr << "Wrong input!!! " <<endl<< "the input should be -> " << "./exe  filename 0/1"<< endl;
    }  
    
    return 0;
}
