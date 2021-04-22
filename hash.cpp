
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int Hash::FunctionHash(Student student)
{
    return (student.getRA() % max_pos);
};

Hash::Hash(int size_vector, int max)
{
    num_items = 0;
    max_items = max;
    max_pos = size_vector;
    structure = new Student[max_pos];
};

Hash::~Hash()
{
    delete[] structure;
};

bool Hash::isFull()
{
    return (num_items == max_items);
};

bool Hash::isEmpty()
{
    return (num_items == 0);
};

int Hash::actualSize()
{
    return (num_items);
};

void Hash::add(Student student)
{
    if (isFull())
    {
        cout << ".........................................." << endl;
        cout << "Hash esta cheia: " << max_items << " de " << max_pos << endl;
        cout << ".........................................." << endl;
    }
    else
    {
        int local = FunctionHash(student);
        while (structure[local].getRA() > 0)
        {
            local = (local + 1) % max_pos;
        }
        structure[local] = student;
        num_items++;
        cout << ".........................................." << endl;
        cout << "Aluno adicionado: " << endl;
        Hash::printStudent(student);
    }
};

void Hash::remove(Student student)
{
    if (isEmpty())
    {
        cout << ".........................................." << endl;
        cout << "Hash esta vazia" << endl;
        cout << ".........................................." << endl;
    }
    else
    {
        int local = FunctionHash(student);
        bool found = false;
        while (structure[local].getRA() != -1)
        {
            if (structure[local].getRA() == student.getRA())
            {
                found = true;
                Student x = structure[local];
                structure[local] = Student(-2, "");
                num_items--;
                cout << ".........................................." << endl;
                cout << "Aluno removido: " << endl;
                Hash::printStudent(x);
                break;
            }
            local = (local + 1) % max_pos;
        }
        if (!found)
        {
            cout << ".........................................." << endl;
            cout << "Aluno nao encontrado!" << endl;
            cout << ".........................................." << endl;
        }
    }
};

void Hash::search(Student &student, bool &search)
{
    int local = FunctionHash(student);
    search = false;
    while (structure[local].getRA() != -1)
    {
        if (structure[local].getRA() == student.getRA())
        {
            search = true;
            student = structure[local];
            break;
        }
        local = (local + 1) % max_pos;
    }
};

void Hash::print()
{
    if (isEmpty())
    {
        cout << ".........................................." << endl;
        cout << "Hash esta vazia" << endl;
        cout << ".........................................." << endl;
    }
    else
    {
        cout << ".........................................." << endl;
        cout << "Tabela Hash:" << endl;
        for (int i = 0; i < max_pos; i++)
        {
            if (structure[i].getRA() > 0)
            {
                cout << i << ": " << structure[i].getRA() << " - ";
                cout << structure[i].getName() << endl;
            }
        }
        cout << ".........................................." << endl;
    }
};

void Hash::printStudent(Student student)
{
    cout << ".........................................." << endl;
    cout << "Ra: " << student.getRA() << endl;
    cout << "Nome: " << student.getName() << endl;
    cout << ".........................................." << endl;
};