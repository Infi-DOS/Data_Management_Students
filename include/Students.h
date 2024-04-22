#ifndef STUDENTS_H
#define STUDENTS_H
#include <string>

using namespace std;
class Students
{
    public:
        //functions for new student
        Students();
        Students(string name, string surname, string am);
        //functions that getting info for  student
        string name() {return NAME;}
        string surname() {return SURNAME;}
        string am() {return AM;}

    private:
        string AM;
        string NAME;
        string SURNAME;
};

#endif // STUDENTS_H
