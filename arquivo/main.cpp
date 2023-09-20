#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

void menu(double medSal, double medFil, double maior, int cont)
{

    int op;
    while (op != 0)
    {
        
        system("cls");
        cout << ("Digite 1 para Média de sálario: ") << endl;
        cout << ("Digite 2 para Média dos filhos: ") << endl;
        cout << ("Digite 3 para O maior sálario : ") << endl;
        cout << ("Digite 4 para Percentual      : ") << endl;
        cout << ("Digite 0 para Sair       ") << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            cout << ("Média de sálario: ") << medSal << endl;
            break;

        case 2:
            cout << ("Média de Filhos: ") << medFil << endl;
            break;

        case 3:
            cout << ("O maior sálario : ") << maior << endl;
            break;

        case 4:
            cout << ("Percentual      : ") << cont << endl;
            break;

        default:
            cout << ("Saindo...") << endl;
            break;
        }
        system("pause");
    }
}

struct banco
{
    string nome;
    double salario;
    int idade;
    int numFilho;
    char sexo;
};

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    banco b[10];
    double medSal = 0, medFil = 0, maior = 0;
    int cont = 0;

    // Responsável por criar o arquivo banco.txt e salvar as informações lá dentro.

    // ofstream arquivo("banco.txt");

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << ("Digite o nome: ") << endl;
    //     cin >> nome[i];
    //     cout << ("Digite o Salario: ") << endl;
    //     cin >> salario[i];
    //     cout << ("Digite o Idade: ") << endl;
    //     cin >> idade[i];
    //     cout << ("Digite o Numero de filhos: ") << endl;
    //     cin >> numFilho[i];
    //     cout << ("Digite o M para masculino e F para Feminino: ") << endl;
    //     cin >> sexo[i];

    //     arquivo << nome[i] << endl;
    //     arquivo << salario[i] << endl;
    //     arquivo << idade[i] << endl;
    //     arquivo << numFilho[i] << endl;
    //     arquivo << sexo[i] << endl;

    //     cout << ("Pessoa ") << +1 << (" Cadastrada");
    //     system("pause");
    //     system("cls");
    // }

    // arquivo.close();

    // Reponsável por pegar o arquivo pronto e colocar na struct

    ifstream arquivo("banco.txt");

    for (int i = 0; i < 10; i++)
    {
        arquivo >> b[i].nome;
        arquivo >> b[i].salario;
        arquivo >> b[i].idade;
        arquivo >> b[i].numFilho;
        arquivo >> b[i].sexo;
    }

    arquivo.close();

    for (int i = 0; i < 10; i++)
    {
        medSal += b[i].salario;
        medFil += b[i].numFilho;

        if (b[i].salario > maior)
        {
            maior = b[i].salario;
        }

        if (b[i].sexo == 'F' & b[i].salario >= 1000)
        {
            cont++;
        }
    }

    // Responsável por fazer as operações que o trabalho pede

    medSal /= 10;
    medFil /= 10;
    cont = (cont / 5) * 100;

    menu(medSal,medFil,maior,cont);

    cout << endl
         << endl;
    return 0;
}