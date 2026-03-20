#include <iostream>
using namespace std;

bool dataValida(int dia, int mes, int ano) {
    if(ano < 0) return false;
    if(mes < 1 || mes > 12) return false;

    int maxDias;
    switch(mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: maxDias = 31; break;
        case 4: case 6: case 9: case 11: maxDias = 30; break;
        case 2:
            if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) maxDias = 29;
            else maxDias = 28;
            break;
        default: return false;
    }
    return dia >= 1 && dia <= maxDias;
}