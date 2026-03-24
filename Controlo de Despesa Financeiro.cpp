#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool dataValida(int dia, int mes, int ano) {

    if(ano <= 0) return false;
    if(mes < 1 || mes > 12) return false;
    if(dia < 1) return false;

    int diasNoMes;

    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

    if(mes == 2){
        diasNoMes = bissexto ? 29 : 28;
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        diasNoMes = 30;
    }
    else{
        diasNoMes = 31;
    }

    if(dia > diasNoMes) return false;

    return true;
}

int main() {

    string categorias[100];
    string tipo[100];
    float valores[100];
    string datas[100];

    int n = 0;
    int opcao;

    float totalAlimentacao = 0, totalLazer = 0, totalTransporte = 0;
    float totalSaude = 0, totalEducacao = 0, totalOutros = 0;

    do {
        cout << "\n===== CONTROLO DE DESPESAS =====\n";
        cout << "1. Registar despesa\n";
        cout << "2. Mostrar despesas\n";
        cout << "3. Total gasto\n";
        cout << "4. Exportar relatorio\n";
        cout << "5. Total por categoria\n";
        cout << "0. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if(opcao == 1){

            if(n >= 100){
                cout << "Limite maximo atingido!\n";
                continue;
            }

            int cat;
            cout << "\nEscolha categoria\n";
            cout << "1 Alimentacao\n2 Lazer\n3 Transporte\n4 Saude\n5 Educacao\n6 Outros\n";
            cin >> cat;

            int t;

            if(cat == 1){
                categorias[n] = "Alimentacao";
                cout << "1 Arroz\n2 Pao\n3 Carne\n4 Peixe\n5 Fruta\n6 Bebidas\n7 Outros\n";
                cin >> t;
                string lista[7] = {"Arroz","Pao","Carne","Peixe","Fruta","Bebidas","Outros"};

                if(t == 7){
                    cin.ignore(1000, '\n');
                    cout << "Digite o nome: ";
                    getline(cin, tipo[n]);
                }
                else if(t >= 1 && t <= 6){
                    tipo[n] = lista[t-1];
                }
                else{
                    cout << "Opcao invalida!\n";
                    continue;
                }
            }

            else if(cat == 2){
                categorias[n] = "Lazer";
                cout << "1 Cinema\n2 Futebol\n3 Internet\n4 Jogos\n5 Musica\n6 Viagem\n7 Outros\n";
                cin >> t;
                string lista[7] = {"Cinema","Futebol","Internet","Jogos","Musica","Viagem","Outros"};

                if(t == 7){
                    cin.ignore(1000, '\n');
                    cout << "Digite o nome: ";
                    getline(cin, tipo[n]);
                }
                else if(t >= 1 && t <= 6){
                    tipo[n] = lista[t-1];
                }
                else{
                    cout << "Opcao invalida!\n";
                    continue;
                }
            }

            else if(cat == 3){
                categorias[n] = "Transporte";
                cout << "1 Autocarro\n2 Taxi\n3 Combustivel\n4 Metro\n5 Mototaxi\n6 Boleia\n7 Outros\n";
                cin >> t;
                string lista[7] = {"Autocarro","Taxi","Combustivel","Metro","Mototaxi","Boleia","Outros"};

                if(t == 7){
                    cin.ignore(1000, '\n');
                    cout << "Digite o nome: ";
                    getline(cin, tipo[n]);
                }
                else if(t >= 1 && t <= 6){
                    tipo[n] = lista[t-1];
                }
                else{
                    cout << "Opcao invalida!\n";
                    continue;
                }
            }

            else if(cat == 4){
                categorias[n] = "Saude";
                cout << "1 Medicamentos\n2 Consulta\n3 Hospital\n4 Analises\n5 Vacina\n6 Farmacia\n7 Outros\n";
                cin >> t;
                string lista[7] = {"Medicamentos","Consulta","Hospital","Analises","Vacina","Farmacia","Outros"};

                if(t == 7){
                    cin.ignore(1000, '\n');
                    cout << "Digite o nome: ";
                    getline(cin, tipo[n]);
                }
                else if(t >= 1 && t <= 6){
                    tipo[n] = lista[t-1];
                }
                else{
                    cout << "Opcao invalida!\n";
                    continue;
                }
            }

            else if(cat == 5){
                categorias[n] = "Educacao";
                cout << "1 Propina\n2 Livros\n3 Material\n4 Internet\n5 Curso\n6 Transporte\n7 Outros\n";
                cin >> t;
                string lista[7] = {"Propina","Livros","Material","Internet","Curso","Transporte","Outros"};

                if(t == 7){
                    cin.ignore(1000, '\n');
                    cout << "Digite o nome: ";
                    getline(cin, tipo[n]);
                }
                else if(t >= 1 && t <= 6){
                    tipo[n] = lista[t-1];
                }
                else{
                    cout << "Opcao invalida!\n";
                    continue;
                }
            }

            else{
                categorias[n] = "Outros";
                cin.ignore(1000, '\n');
                cout << "Digite descricao: ";
                getline(cin, tipo[n]);
            }

            cout << "Valor: ";
            cin >> valores[n];

            int dia, mes, ano;

            do{
                cout << "Dia: ";
                cin >> dia;
                cout << "Mes: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                if(!dataValida(dia, mes, ano)){
                    cout << "Data invalida! Tente novamente.\n";
                }

            } while(!dataValida(dia, mes, ano));

            stringstream ss;
            ss << dia << "/" << mes << "/" << ano;
            datas[n] = ss.str();

            if(categorias[n] == "Alimentacao") totalAlimentacao += valores[n];
            else if(categorias[n] == "Lazer") totalLazer += valores[n];
            else if(categorias[n] == "Transporte") totalTransporte += valores[n];
            else if(categorias[n] == "Saude") totalSaude += valores[n];
            else if(categorias[n] == "Educacao") totalEducacao += valores[n];
            else totalOutros += valores[n];

            n++;
            cout << "Despesa registada com sucesso!\n";
        }

    } while(opcao != 0);

    return 0;
}