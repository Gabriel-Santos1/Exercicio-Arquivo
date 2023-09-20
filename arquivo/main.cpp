#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

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
    medSal /= 10;
    medFil /= 10;
    cont = (cont/5)*100;



    cout << ("Média de sálario: ") << medSal << endl;
    cout << ("Média dos filhos: ") << medFil << endl;
    cout << ("O maior sálario : ") << maior << endl;
    cout << ("Percentual      : ") << cont << endl;


    cout << endl
         << endl;
    return 0;
}