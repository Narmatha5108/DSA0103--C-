#include <iostream>
#include <string>
using namespace std;
class Address {
 string city; int pin;
public:
 Address(string c,int p):city(c),pin(p){cout<<"Address constructed\n";}
 ~Address(){cout<<"Address destroyed\n";}
 string str() const{return city+"-"+to_string(pin);}
};
class Person {
protected: string name; int age; Address address;
public:
 Person(string n,int a,string c,int p):name(n),age(a),address(c,p){cout<<"Person constructed\n";}
 virtual ~Person(){cout<<"Person destroyed\n";}
};
class Course {
 string title;
public:
 Course(string t):title(t){cout<<"Course constructed\n";}
 ~Course(){cout<<"Course destroyed\n";}
 string get() const{return title;}
};
class Student:public Person {
 long long reg; Course course;
public:
 Student(string n,int a,long long r,string c,int p,string co)
 :Person(n,a,c,p),reg(r),course(co){cout<<"Student constructed\n";}
 ~Student() override{cout<<"Student destroyed\n";}
 void print() const{cout<<reg<<' '<<name<<" ("<<age<<") "<<address.str()<<" Course: "<<course.get()<<'\n';}
};
struct Engine{Engine(){cout<<"Engine ";}~Engine(){cout<<"~Engine ";}};
struct Vehicle{Vehicle(){cout<<"Vehicle ";}~Vehicle(){cout<<"~Vehicle ";}};
struct Car:Vehicle{Engine e;Car(){cout<<"Car ";}~Car(){cout<<"~Car ";}};
int main(){
 cout<<"MEMBER AND BASE CONSTRUCTION:\n";
 {Student s("Kavya",19,192311001,"Salem",636001,"C++");s.print();}
 cout<<"\nCAR ORDER:\n";
 {Car c;cout<<"| ";}
 cout<<'\n';
}
