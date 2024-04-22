#ifndef COURSES_H
#define COURSES_H
#include <string>

using namespace std;
class Courses
{
    public:
        //functions for new courses
        Courses();
        Courses(string courseid,int grade);
        //functions that getting info for  courses
        string courseid() {return COURSEID;}
        int grade() {return GRADE;}


    private:
        string COURSEID;    //Course UniversityID
        int GRADE;         //Course grade

};

#endif // COURSES_H





