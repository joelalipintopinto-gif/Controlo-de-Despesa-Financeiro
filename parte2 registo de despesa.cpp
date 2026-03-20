#include <iostream>
#include <string>
using namespace std;

void registarDespesa(string categorias[], string tipo[], string datas[], float valores[], int &n,
                     float &totalAlimentacao, float &totalLazer, float &totalTransporte,
                     float &totalSaude, float &totalEducacao, float &totalOutros,
                     bool (*validarData)(int,int,int)) {

    int cat;
    cout << "\nEscolha categoria\n1 Alimentacao\n2 Lazer\n3 Transporte\n4 Saude\n5 Educacao\n6 Outros\n";
    cin >> cat; cin.ignore();

    if(cat == 1) categorias[n] = "Alimentacao";
    else if(cat == 2) categorias[n] = "Lazer";
    else if(cat == 3) categorias[n] = "Transporte";
    else if(cat == 4) categorias[n] = "Saude";
    else if(cat == 5) categorias[n] = "Educacao";
    else categorias[n] = "Outros";

    string lista[6]; int t;
    if(cat>=1 && cat<=5){
        switch(cat){
            case 1:
                cout << "\nTipo de alimentacao\n1 Arroz\n2 Pao\n3 Carne\n4 Peixe\n5 Fruta\n6 Bebidas\n7 Outros\n";
                cin >> t; cin.ignore();
                lista[0]="Arroz"; lista[1]="Pao"; lista[2]="Carne"; lista[3]="Peixe"; lista[4]="Fruta"; lista[5]="Bebidas";
                if(t>=1 && t<=6) tipo[n]=lista[t-1]; else { cout<<"Digite nome: "; getline(cin,tipo[n]); }
                break;
            case 2:
                cout << "\nTipo de lazer\n1 Cinema\n2 Futebol\n3 Internet\n4 Jogos\n5 Musica\n6 Viagem\n7 Outros\n";
                cin >> t; cin.ignore();
                lista[0]="Cinema"; lista[1]="Futebol"; lista[2]="Internet"; lista[3]="Jogos"; lista[4]="Musica"; lista[5]="Viagem";
                if(t>=1 && t<=6) tipo[n]=lista[t-1]; else { cout<<"Digite nome: "; getline(cin,tipo[n]); }
                break;
            case 3:
                cout << "\nTipo de transporte\n1 Autocarro\n2 Taxi\n3 Combustivel\n4 Metro\n5 Mototaxi\n6 Boleia\n7 Outros\n";
                cin >> t; cin.ignore();
                lista[0]="Autocarro"; lista[1]="Taxi"; lista[2]="Combustivel"; lista[3]="Metro"; lista[4]="Mototaxi"; lista[5]="Boleia";
                if(t>=1 && t<=6) tipo[n]=lista[t-1]; else { cout<<"Digite nome: "; getline(cin,tipo[n]); }
                break;
            case 4:
                cout << "\nTipo de saude\n1 Medicamentos\n2 Consulta\n3 Hospital\n4 Analises\n5 Vacina\n6 Farmacia\n7 Outros\n";
                cin >> t; cin.ignore();
                lista[0]="Medicamentos"; lista[1]="Consulta"; lista[2]="Hospital"; lista[3]="Analises"; lista[4]="Vacina"; lista[5]="Farmacia";
                if(t>=1 && t<=6) tipo[n]=lista[t-1]; else { cout<<"Digite nome: "; getline(cin,tipo[n]); }
                break;
            case 5:
                cout << "\nTipo de educacao\n1 Propina\n2 Livros\n3 Material escolar\n4 Internet estudo\n5 Curso\n6 Transporte escolar\n7 Outros\n";
                cin >> t; cin.ignore();
                lista[0]="Propina"; lista[1]="Livros"; lista[2]="Material"; lista[3]="Internet"; lista[4]="Curso"; lista[5]="Transporte";
                if(t>=1 && t<=6) tipo[n]=lista[t-1]; else { cout<<"Digite nome: "; getline(cin,tipo[n]); }
                break;
        }
    } else {
        cout << "Digite o nome: "; getline(cin, tipo[n]);
    }

    cout << "Valor: "; cin >> valores[n]; cin.ignore();

    int dia, mes, ano; bool valida=false;
    while(!valida){
        cout << "Data (dd mm aaaa): "; cin >> dia >> mes >> ano; cin.ignore();
        if(validarData(dia,mes,ano)){
            char buffer[11]; sprintf(buffer,"%02d/%02d/%04d",dia,mes,ano);
            datas[n]=buffer;
            valida=true;
        } else cout<<"Data invalida! Tente novamente.\n";
    }

    if(categorias[n]=="Alimentacao") totalAlimentacao+=valores[n];
    else if(categorias[n]=="Lazer") totalLazer+=valores[n];
    else if(categorias[n]=="Transporte") totalTransporte+=valores[n];
    else if(categorias[n]=="Saude") totalSaude+=valores[n];
    else if(categorias[n]=="Educacao") totalEducacao+=valores[n];
    else totalOutros+=valores[n];

    n++;
    cout << "Despesa registada!\n";
}