#include "student.h"


class Hash{
    private:
    int FunctionHash(Student student);
    int max_items;
    int max_pos;
    int num_items;
    Student* structure;

    public:
    Hash(int size_vector, int max);
    ~Hash();
    bool isFull();
    bool isEmpty();
    int actualSize();
    void add(Student student);
    void remove(Student student);
    void search(Student& student, bool& search);
    void print();
    void printStudent(Student student);
};