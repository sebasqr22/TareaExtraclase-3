#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

class CRC
{
public:
    //Function that converts an integer to binary string
    string toBin(long long int num){
        string binary = "";
        while (num){
            if (num & 1)
                binary = "1" + binary;
            else
                binary = "0" + binary;
            num = num>>1;
        }
        return binary;
    }
    
    //Function that converts a binary string to decimal
    long long int toDec(string binary){
        long long int num = 0;
        for (int i=0; i<binary.length(); i++){
            if (binary.at(i)=='1')
                num += 1 << (binary.length() - i - 1);
        }
        return num;
    }
    
    //Function that calculates CRC and codeword
    CRC(string dataword, string generator)
    {
        int l_gen = generator.length();
        long long int gen = toDec(generator);
    
        long long int dword = toDec(dataword);
    
        //Add 0's the the dividend
        long long int dividend = dword << (l_gen-1);      
    
        int shft = (int) ceill(log2l(dividend+1)) - l_gen; 
        long long int rem;
    
        while ((dividend >= gen) || (shft >= 0)){
    
            //The remainder is generated
            rem = (dividend >> shft) ^ gen;               
            dividend = (dividend & ((1 << shft) - 1)) | (rem << shft);
    
            //Change the shft variable
            shft = (int) ceill(log2l(dividend + 1)) - l_gen;
        }
    
        //AND the initial dividend with the remainder
        long long int codeword = (dword << (l_gen - 1)) | dividend;
        cout << "Remainder: " << toBin(dividend) << endl;
        cout << "Codeword : " << toBin(codeword) << endl;
    }
};