#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    string nome[10];
    double salario[10];
    int idade[10], numFilho[10];
    char sexo[10];

    double medSal = 0, medFil = 0, maior = 0;
    int cont=0;

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

    ifstream arquivo("banco.txt");

    for (int i = 0; i < 10; i++)
    {
        arquivo >> nome[i];
        arquivo >> salario[i];
        medSal += salario[i];
        if (maior <= salario[i])
        {
            maior = salario[i];
        }
        arquivo >> idade[i];
        arquivo >> numFilho[i];
        medFil += numFilho[i];
        arquivo >> sexo[i];
        if (sexo[i] == 'F' && salario[i]>1000)
        {
            cont++;
        }
    }

    system("pause");
    arquivo.close();

    cout << ("Nome: ") << nome[0] << endl;
    cout << ("Salario: ") << salario[1] << endl;
    cout << ("Idade: ") << idade[3] << endl;

    cout << endl
         << endl;
    return 0;
}