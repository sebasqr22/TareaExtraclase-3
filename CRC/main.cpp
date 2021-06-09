#include <stdio.h>
#include <iostream>
#include "crc.h"
 
using namespace std;
 
 
int main()
{
    string dataword, generator;
    cout << "Please enter a bits dataword: ";
    cin >> dataword;
    cout << "\n====================================" << endl << endl;
    cout << "Please enter a bits generator: ";
    cin >> generator;
    cout << "\n====================================" << endl << endl;
    
    CRC(dataword, generator);
    return 0;
}