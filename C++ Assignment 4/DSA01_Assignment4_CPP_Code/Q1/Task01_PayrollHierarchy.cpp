#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Staff {
    string name; int id;
protected:
    double basic;
    static constexpr double DA_RATE = 0.42;
public:
    Staff(string n, int i, double b): name(n), id(i), basic(b) {}
    virtual double pay() const = 0;
    void display() const { cout << name << " (ID: " << id << ") - Pay: " << fixed << setprecision(2) << pay() << '\n'; }
    virtual ~Staff() = default;
};
class Professor: public Staff {
    double research;
public:
    Professor(string n,int i,double b,double r):Staff(n,i,b),research(r){}
    double pay() const override { return basic + basic*DA_RATE + research; }
};
class LabAssistant: public Staff {
public:
    LabAssistant(string n,int i,double b):Staff(n,i,b){}
    double pay() const override { return basic + basic*DA_RATE; }
};
class GuestFaculty: public Staff {
    double hours, rate;
public:
    GuestFaculty(string n,int i,double h,double r):Staff(n,i,0),hours(h),rate(r){}
    double pay() const override { return hours*rate; }
};
int main() {
    vector<unique_ptr<Staff>> people;
    people.push_back(make_unique<Professor>("Anand",101,50000,8000));
    people.push_back(make_unique<LabAssistant>("Meena",102,30000));
    people.push_back(make_unique<GuestFaculty>("Ravi",103,40,750));
    cout << "COLLEGE PAYROLL\n";
    for (const auto& p:people) p->display();
}
