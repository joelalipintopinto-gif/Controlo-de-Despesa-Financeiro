#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void exportarRelatorio(string datas[], string categorias[], string tipo[], float valores[], int n,
                       float totalAlimentacao,float totalLazer,float totalTransporte,float totalSaude,float totalEducacao,float totalOutros){
    ofstream ficheiro("data/extrato_mes.txt");
    for(int i=0;i<n;i++){
        ficheiro << datas[i] << " | " << categorias[i] << " | " << tipo[i] << " | " << valores[i] << endl;
    }
    float total=totalAlimentacao+totalLazer+totalTransporte+totalSaude+totalEducacao+totalOutros;
    ficheiro << "\nTOTAL: " << total;
    ficheiro.close();
    cout << "Relatorio criado: data/extrato_mes.txt\n";
}

void totalPorCategoria(float totalAlimentacao,float totalLazer,float totalTransporte,float totalSaude,float totalEducacao,float totalOutros){
    cout << "\n=== TOTAL POR CATEGORIA ===\n";
    cout << "Alimentacao: " << totalAlimentacao << endl;
    cout << "Lazer: " << totalLazer << endl;
    cout << "Transporte: " << totalTransporte << endl;
    cout << "Saude: " << totalSaude << endl;
    cout << "Educacao: " << totalEducacao << endl;
    cout << "Outros: " << totalOutros << endl;
}