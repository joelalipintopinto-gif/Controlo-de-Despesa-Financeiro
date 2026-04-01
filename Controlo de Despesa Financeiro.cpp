#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função para validar data
bool dataValida(int dia, int mes, int ano){
    if(ano < 0) return false;
    if(mes < 1 || mes > 12) return false;

    int maxDias;
    switch(mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDias = 31; break;
        case 4: case 6: case 9: case 11:
            maxDias = 30; break;
        case 2:
            // Verifica ano bissexto
            if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) maxDias = 29;
            else maxDias = 28;
            break;
        default: return false;
    }

    if(dia < 1 || dia > maxDias) return false;

    return true;
}

int main() {
    string categorias[100], tipo[100], datas[100];
    float valores[100];
    int n = 0, opcao;

    float totalAlimentacao = 0, totalLazer = 0, totalTransporte = 0, totalSaude = 0, totalEducacao = 0, totalOutros = 0;

    do {
        cout << "\n===== CONTROLO DE DESPESAS =====\n";
        cout << "1. Registar despesa\n2. Mostrar despesas\n3. Total gasto\n4. Exportar relatorio\n5. Total por categoria\n0. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        if(opcao == 1){
            int cat;
            cout << "\nEscolha categoria\n1 Alimentacao\n2 Lazer\n3 Transporte\n4 Saude\n5 Educacao\n6 Outros\n";
            cin >> cat;
            cin.ignore();

            // Determina a categoria
            if(cat == 1) categorias[n] = "Alimentacao";
            else if(cat == 2) categorias[n] = "Lazer";
            else if(cat == 3) categorias[n] = "Transporte";
            else if(cat == 4) categorias[n] = "Saude";
            else if(cat == 5) categorias[n] = "Educacao";
            else categorias[n] = "Outros";

            // Subcategoria com opções ou entrada livre
            if(cat >=1 && cat <=5){
                int t;
                if(cat == 1){
                    cout << "\nTipo de alimentacao\n1 Arroz\n2 Pao\n3 Carne\n4 Peixe\n5 Fruta\n6 Bebidas\n7 Outros\n";
                    cin >> t; cin.ignore();
                    if(t >=1 && t <=6){
                        string lista[6]={"Arroz","Pao","Carne","Peixe","Fruta","Bebidas"};
                        tipo[n] = lista[t-1];
                    } else {
                        cout << "Digite o nome da alimentacao: ";
                        getline(cin, tipo[n]);
                    }
                }
                else if(cat == 2){
                    cout << "\nTipo de lazer\n1 Cinema\n2 Futebol\n3 Internet\n4 Jogos\n5 Musica\n6 Viagem\n7 Outros\n";
                    cin >> t; cin.ignore();
                    if(t >=1 && t <=6){
                        string lista[6]={"Cinema","Futebol","Internet","Jogos","Musica","Viagem"};
                        tipo[n] = lista[t-1];
                    } else {
                        cout << "Digite nome do lazer: ";
                        getline(cin, tipo[n]);
                    }
                }
                else if(cat == 3){
                    cout << "\nTipo de transporte\n1 Autocarro\n2 Taxi\n3 Combustivel\n4 Metro\n5 Mototaxi\n6 Boleia\n7 Outros\n";
                    cin >> t; cin.ignore();
                    if(t >=1 && t <=6){
                        string lista[6]={"Autocarro","Taxi","Combustivel","Metro","Mototaxi","Boleia"};
                        tipo[n] = lista[t-1];
                    } else {
                        cout << "Digite o nome do transporte: ";
                        getline(cin, tipo[n]);
                    }
                }
                else if(cat == 4){
                    cout << "\nTipo de saude\n1 Medicamentos\n2 Consulta\n3 Hospital\n4 Analises\n5 Vacina\n6 Farmacia\n7 Outros\n";
                    cin >> t; cin.ignore();
                    if(t >=1 && t <=6){
                        string lista[6]={"Medicamentos","Consulta","Hospital","Analises","Vacina","Farmacia"};
                        tipo[n] = lista[t-1];
                    } else {
                        cout << "Digite o nome da Saude: ";
                        getline(cin, tipo[n]);
                    }
                }
                else if(cat == 5){
                    cout << "\nTipo de educacao\n1 Propina\n2 Livros\n3 Material escolar\n4 Internet estudo\n5 Curso\n6 Transporte escolar\n7 Outros\n";
                    cin >> t; cin.ignore();
                    if(t >=1 && t <=6){
                        string lista[6]={"Propina","Livros","Material","Internet","Curso","Transporte"};
                        tipo[n] = lista[t-1];
                    } else {
                        cout << "Digite o nome da Educacao: ";
                        getline(cin, tipo[n]);
                    }
                }
            } else { // Categoria "Outros"
                cout << "Digite o nome : ";
                getline(cin, tipo[n]);
            }

            // Valor
            cout << "Valor: ";
            cin >> valores[n];
            cin.ignore();

            // Data com validação
            int dia, mes, ano;
            bool valida = false;
            while(!valida){
                cout << "Data dia: ";
                cout << " mes: ";
                cout << " ano: ";
                cin >> dia;
				cin >> mes;
				cin >> ano;
                cin.ignore();
                if(dataValida(dia, mes, ano)){
                    char buffer[11];
                    sprintf(buffer,"%02d/%02d/%04d", dia, mes, ano);
                    datas[n] = buffer;
                    valida = true;
                } else {
                    cout << "Data invalida! Tente novamente.\n";
                }
            }

            // Atualiza totais
            if(categorias[n] == "Alimentacao") totalAlimentacao += valores[n];
            else if(categorias[n] == "Lazer") totalLazer += valores[n];
            else if(categorias[n] == "Transporte") totalTransporte += valores[n];
            else if(categorias[n] == "Saude") totalSaude += valores[n];
            else if(categorias[n] == "Educacao") totalEducacao += valores[n];
            else totalOutros += valores[n];

            n++;
            cout << "Despesa registada!\n";
        }

        else if(opcao == 2){
            cout << "\nLISTA DE DESPESAS\n";
            for(int i=0;i<n;i++){
                cout << datas[i] << " | " << categorias[i] << " | " << tipo[i] << " | " << valores[i] << endl;
            }
        }

        else if(opcao == 3){
            float total = totalAlimentacao + totalLazer + totalTransporte + totalSaude + totalEducacao + totalOutros;
            cout << "Total gasto: " << total << endl;
        }

        else if(opcao == 4){
            ofstream ficheiro("extrato_mes.txt");
            for(int i=0;i<n;i++){
                ficheiro << datas[i] << " | " << categorias[i] << " | " << tipo[i] << " | " << valores[i] << endl;
            }
            float total = totalAlimentacao + totalLazer + totalTransporte + totalSaude + totalEducacao + totalOutros;
            ficheiro << "\nTOTAL: " << total;
            ficheiro.close();
            cout << "Relatorio criado\n";
        }

        else if(opcao == 5){
            cout << "\n=== TOTAL POR CATEGORIA ===\n";
            cout << "Alimentacao: " << totalAlimentacao << endl;
            cout << "Lazer: " << totalLazer << endl;
            cout << "Transporte: " << totalTransporte << endl;
            cout << "Saude: " << totalSaude << endl;
            cout << "Educacao: " << totalEducacao << endl;
            cout << "Outros: " << totalOutros << endl;
        }

    } while(opcao != 0);

    return 0;
}
