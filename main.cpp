#include <iostream>
#include "hash.h"

using namespace std;

    void StartMsg(){
        system("CLS");
        cout << ".........................................." << endl;
        cout << "Programa gerador de Hash!" << endl;
        cout << ".........................................." << endl;
        cout << "by Durval Sproesser" << endl;
        cout << ".........................................." << endl;
    };

    
int main()
{
    int tv, mv, option, ra;
    string name;
    bool search;
    float charge;
    StartMsg();
    cout << "Digite o tamanho da Hash: ";
    cin >> tv;
    cout << "Digite o numero maximo de elementos: ";
    cin >> mv;
    charge = (float)mv / (float)tv;
    system("CLS");

    Hash studentHash(tv, mv);

    do
    {
        cout << ".........................................." << endl;
        cout << "Tamanho da Hash: " << tv << " - Max Elementos: " << mv << endl;
        cout << "Fator de carga: " << charge << endl;
        cout << ".........................................." << endl;
        cout << "Digite 0 para parar o programa." << endl;
        cout << "Digite 1 para inserir um aluno." << endl;
        cout << "Digite 2 para remover um aluno." << endl;
        cout << "Digite 3 para procurar um aluno." << endl;
        cout << "Digite 4 para imprimir a Hash." << endl;
        cout << "Digite 9 para limpar a tela." << endl;
        cout << ".........................................." << endl;
        cout << ">>> ";

        cin >> option;

        system("CLS");


        if (option == 1)
        {
            cout << "Digite o RA do aluno: ";
            cin >> ra;
            cout << "Digite o Nome do aluno: ";
            cin >> name;
            Student student(ra, name);
            studentHash.add(student);
        }
        if(option == 2)
        {
            cout << "Digite o RA do aluno: ";
            cin >> ra;
            Student student(ra, "");
            studentHash.remove(student);
        }
        if (option == 3)
        {
            cout << "Digite o RA do aluno: ";
            cin >> ra;
            Student student(ra, "");
            search = false;
            studentHash.search(student, search);
            if (search)
            {
                studentHash.printStudent(student);
            }
            else
            {
                cout << ".........................................." << endl;
                cout << "Aluno nao encontrado." << endl;
                cout << ".........................................." << endl;
            }
        }
        if (option == 4)
        {
            studentHash.print();
        }
        if (option == 9)
        {
            StartMsg();;
        }
    } while (option != 0);

    return 0;
}