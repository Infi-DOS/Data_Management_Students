#include <iostream>
#include <vector>
#include <string>
#include <Students.h>
#include <Courses.h>
#include <fstream>


using namespace std;

int main()
{
    char choice;
    vector<Students> s;
    vector<Courses> c;
    Students tempstudent;
    Courses tempcourses;

    string name,surname,id,filename,am;
    int grade;
    int k=0;
    long long unsigned int i;

    ofstream studentfile,studentslist;
    studentslist.open("studentslist.txt",ios::app);

    cout << "\n              VATHMOLOGIO              \n";
    cout << "***************************************\n";

    do
    {
        cout << "Create a new student"<<endl;
        cout << "Give name:"<<endl;
        cin >> name;
        cout << "Give surname:"<<endl;
        cin >> surname;
        cout << "Give AM:"<<endl;
        cin >> am;
        studentslist<<am<<" "<<name<<" "<<surname<<endl;
        tempstudent=Students(name,surname,am);
        s.push_back(tempstudent);
        studentfile.open(am+".txt",ios::app);

        cout<<"You are going to import grades for student:"<<s[k].name()<<" "<<s[k].surname()<<" with AM:"<<s[k].am()<<endl;
        do
        {
            cout << "Give Course ID:"<<endl;
            cin >> id;
            studentfile<<id<<" ";
            cout << "Give grade(from 5 to 10):"<<endl;
            cin >> grade;
            studentfile<<grade<<endl;
            tempcourses=Courses(id,grade);
            c.push_back(tempcourses);

            cout << "Do you want more courses for Student with AM:"<<s[k].am()<<" (y/any)"<<endl;
            cin>>choice;
        }
        while(choice=='y');

        studentfile.close();
        cout << "Do you want more Students to add? (y/any)"<<endl;
        cin>>choice;
        k++;

    }
    while(choice=='y');
    studentslist.close();

    cout << "Do you want to print grades for a Student? (y/any)"<<endl;
    cin>>choice;
    while(choice=='y')
    {
        cout << "Give AM:";
        cin >> am;
        choice='z';
        for(i=0;i<s.size();i++)
        {
            if(s[i].am()==am)
            {
                cout<<"This am exist"<<endl;
                ifstream filesearch;
                filesearch.open(am+".txt");
                cout<<"Give the course ID to print the grade:";
                cin >> id;
                string arg1,arg2;
                while(filesearch>>arg1>>arg2)
                {
                    if(arg1==id)
                        cout<<"The grade for  course with ID: "<<arg1<<" is :"<<arg2<<endl;
                }
            }
            if(s[i].am()!=am && i==s.size()-1 && choice!='z')
                cout<<"This am does not exist"<<endl;
        }
        cout << "Do you want for another Student? (y/any)"<<endl;
        cin >> choice;
    }
    cout << "Exiting..."<<endl;
    return 0;

}
