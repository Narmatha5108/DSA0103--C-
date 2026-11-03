#include <iostream>
#include <string>
using namespace std;
class Person {
protected: string name, phone; int id;
public:
 Person(string n,int i,string p):name(n),phone(p),id(i){}
 void showPerson() const { cout<<"Name: "<<name<<", ID: "<<id<<", Phone: "<<phone<<'\n'; }
};
class Student: virtual public Person {
protected: string programme; double cgpa;
public:
 Student(string n,int i,string p,string pr,double g):Person(n,i,p),programme(pr),cgpa(g){}
 void showStudent() const { cout<<"Programme: "<<programme<<", CGPA: "<<cgpa<<'\n'; }
};
class Staff: virtual public Person {
protected: string department; double salary;
public:
 Staff(string n,int i,string p,string d,double s):Person(n,i,p),department(d),salary(s){}
 void showStaff() const { cout<<"Department: "<<department<<", Salary: "<<salary<<'\n'; }
};
class TeachingAssistant: public Student, public Staff {
public:
 TeachingAssistant(string n,int i,string p,string pr,double g,string d,double s)
 :Person(n,i,p),Student(n,i,p,pr,g),Staff(n,i,p,d,s){}
 void show() const { showPerson(); showStudent(); showStaff(); }
};
class ResearchScholar: public Student {
 double fellowship;
public:
 ResearchScholar(string n,int i,string p,string pr,double g,double f)
 :Person(n,i,p),Student(n,i,p,pr,g),fellowship(f){}
 void show() const { showPerson(); showStudent(); cout<<"Fellowship: "<<fellowship<<'\n'; }
};
int main() {
 cout<<"TEACHING ASSISTANT\n";
 TeachingAssistant t("Kavya",201,"9876543210","CSE",8.7,"Computer Science",25000); t.show();
 cout<<"\nRESEARCH SCHOLAR\n";
 ResearchScholar r("Arun",202,"9876501234","IT",9.1,12000); r.show();
}
