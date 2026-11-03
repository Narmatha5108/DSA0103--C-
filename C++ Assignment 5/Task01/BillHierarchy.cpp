#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;
struct Bill{string patient;explicit Bill(string p):patient(move(p)){}virtual ~Bill()=default;virtual double total()const=0;virtual string type()const=0;virtual void print()const{cout<<type()<<" "<<patient<<": "<<total()<<'\n';}};
struct OutPatient:Bill{double consultation,tests;OutPatient(string p,double c,double t):Bill(move(p)),consultation(c),tests(t){if(c<0||t<0)throw invalid_argument("negative charge");}double total()const override{return consultation+tests;}string type()const override{return "OP";}};
struct InPatient:Bill{int days;double rate,procedure,medicine;InPatient(string p,int d,double r,double pr,double m):Bill(move(p)),days(d),rate(r),procedure(pr),medicine(m){if(d<0||r<0||pr<0||m<0)throw invalid_argument("negative charge");}double total()const override{return days*rate+procedure+medicine;}string type()const override{return "IP";}};
struct DayCare:Bill{double packagePrice;DayCare(string p,double v):Bill(move(p)),packagePrice(v){}double total()const override{return packagePrice;}string type()const override{return "DayCare";}};
struct Emergency:Bill{double base,hourly;int hours;Emergency(string p,double b,double h,int n):Bill(move(p)),base(b),hourly(h),hours(n){}double total()const override{return base+hourly*hours;}string type()const override{return "Emergency";}};
struct Payer{virtual ~Payer()=default;virtual double amountCovered(const Bill&)const=0;virtual string name()const=0;};
struct SelfPay:Payer{double amountCovered(const Bill&b)const override{return b.total();}string name()const override{return "SelfPay";}};
struct Insurance:Payer{double limit,copay;Insurance(double l,double c):limit(l),copay(c){}double amountCovered(const Bill&b)const override{return min(limit,b.total()*(1-copay/100));}string name()const override{return "Insurance";}};
struct GovernmentScheme:Payer{double rate;GovernmentScheme(double r):rate(r){}double amountCovered(const Bill&b)const override{return min(rate,b.total());}string name()const override{return "Government";}};
struct CorporatePayer:Payer{double percent;CorporatePayer(double p):percent(p){}double amountCovered(const Bill&b)const override{return b.total()*percent/100;}string name()const override{return "Corporate";}};
struct MaternityBill:Bill{double package,extra;MaternityBill(string p,double a,double b):Bill(move(p)),package(a),extra(b){}double total()const override{return package+extra;}string type()const override{return "Maternity";}};
int main(){vector<unique_ptr<Bill>> bills;bills.push_back(make_unique<OutPatient>("Ravi",500,1200));bills.push_back(make_unique<InPatient>("Meena",3,2500,40000,0));bills.push_back(make_unique<DayCare>("Anu",18000));bills.push_back(make_unique<Emergency>("Kumar",2000,500,4));vector<unique_ptr<Payer>> payers;payers.push_back(make_unique<SelfPay>());payers.push_back(make_unique<Insurance>(50000,20));payers.push_back(make_unique<GovernmentScheme>(15000));payers.push_back(make_unique<CorporatePayer>(90));for(auto&b:bills){b->print();for(auto&p:payers)cout<<"  "<<p->name()<<" covers "<<p->amountCovered(*b)<<'\n';}bills.push_back(make_unique<MaternityBill>("Sara",30000,2500));cout<<"Extension "<<bills.back()->type()<<" "<<bills.back()->total()<<'\n';}
