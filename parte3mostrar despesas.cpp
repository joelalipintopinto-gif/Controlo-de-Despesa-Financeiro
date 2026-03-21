#include <iostream>
#include <string>
using namespace std;

void mostrarDespesas(string datas[], string categorias[], string tipo[], float valores[], int n){
    cout << "\nLISTA DE DESPESAS\n";
    for(int i=0;i<n;i++){
        cout << datas[i] << " | " << categorias[i] << " | " << tipo[i] << " | " << valores[i] << endl;
    }
}

void totalGasto(float totalAlimentacao,float totalLazer,float totalTransporte,float totalSaude,float totalEducacao,float totalOutros){
    float total=totalAlimentacao+totalLazer+totalTransporte+totalSaude+totalEducacao+totalOutros;
    cout << "Total gasto: " << total << endl;
}