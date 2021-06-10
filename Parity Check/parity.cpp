#include <iostream>
#include <bits/stdc++.h>
#define bool int

using namespace std;

bool Paridad(unsigned int num){
    bool paridad = 0;
    while(num){
        num = num & (num-1);
    }
    return paridad;
}

int main(){
    bool corriendo = true;
    unsigned int num;
    int operacion = 0;
    

    while(corriendo){
        cout << endl << "Ingrese el numero para saber la paridad de sus bits: ";
        cin >> num;
        cout << "\n";
        cout << "Paridad: " << num << " = " << (Paridad(num)? "par": "impar") << "\n";
        getchar();
        cout << "Desea continuar (0 si, 1 no): ";
        cin >> operacion;
        if(operacion == 1){
            exit(1);
        }

    }
    return 0;
}